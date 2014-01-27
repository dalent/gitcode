#! /bin/bash -
set -u
set -e
ip_list=$1
name=$2

do_kill(){
	pid_list_size=`ssh jujintao@$ip "ps axu | grep $name | grep -v grep" | awk '{print $2}' | wc -l`
	ssh jujintao@$ip "ps -ef|grep $name |grep -v grep| cut -c 9-15 |xargs kill "
}

do_wait(){
	sleep 2
	while [ 1 -eq 1 ]
	do
		pid_list_size1=`ssh jujintao@$ip "ps axu | grep $name | grep -v grep" | awk '{print $2}' | wc -l`
		echo $pid_list_size1 $pid_list_size
		if [[ $pid_list_size1 -eq $pid_list_size ]];then
			echo $name ok
			break
		fi
	done
}

if [[ -f $ip_list ]];then
	for ip in `cat $ip_list`
	do
		do_kill
		do_wait
	done
else
	NUM=$#
	for((i=1;i<=$#;i++))
	do
		ip=$i
		do_kill
		do_wait
	done
fi
