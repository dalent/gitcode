#!/bin/bash - 

get_mysql_result(){
	sql="select identity,code,verified,if(verified =1,verify_time - send_time,0) as period from t_verify_code where from_unixtime(send_time) like '$date%' and type=3 "
	echo "$sql" | $mysql > .sms.log
}

check_result(){
    local sent=$(grep -E  "^1" .sms.log|wc -l | tr "\t" " " | tr -s " ")
	local recv=$(grep -E  "^1" .sms.log|awk -v period=$period 'BEGIN{m =0} {if($3 == 1 && $4 < period) {m++;}} END{printf("%d",m);}')
    local rate=$(echo "scale=2; $recv/$sent*100" | bc -l)
	echo "总数量: $sent"
	echo "收到的数量: $recv"
	echo "总抵达率: ${rate}%"
}
check_mobile(){
    local sent=$(grep -E  "^1" .sms.log|grep -E "^13[4-9]|^147|^15[0-2]|^15[7-9]|^182|^183|^187|^188"|wc -l | tr "\t" " " | tr -s " ")
    local recv=$(grep -E "^1" .sms.log|grep -E "^13[4-9]|^147|^15[0-2]|^15[7-9]|^182|^183|^187|^188"|awk -v period=$period 'BEGIN{m=0} {if($3==1 && $4 < period) {m++}} END{print m;}')
    local rate=$(echo "scale=2; $recv/$sent*100" | bc -l)

	echo "移动发送量:$sent"
	echo "移动收到量: $recv"
	echo "移动抵达率: ${rate}%"
}

echo_help(){
	cat <<EOF
	./get_send_sms.sh period
 	./get_send_sms.sh date period
	./get_send_sms.sh 
EOF
}

declare date
declare period
if [[ $# == 1 && $1 == '?' ]]
then
	echo_help
	exit 1
fi

if [[ $# == 1 ]]
then
	period=$1
	date=`date +%Y-%m-%d`
    echo "${period}秒内到达统计"
elif [[ $# == 2 ]]
then 
 	date=$1
	period=$2
else
	date=`date +%Y-%m-%d`
	period=120
    echo "${period}秒内到达统计"
fi
 
mysql='mysql -uroot -h172.17.0.2 uaccount -B -N '
get_mysql_result
check_result
check_mobile
exit 0
