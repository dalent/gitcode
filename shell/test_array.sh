#!/bin/bash - 
cat <<EOF
====成员====
\${array[@]}
====大小====
\${#array[@]}
====赋值====
array[i]=k
====删除====
unset array[i]
EOF
set -x
declare -a test
test=("1" "2")
echo ${test[@]}
echo ${#test[*]}
test[0]="3"
echo ${test[@]}
unset test[0]
echo ${test[@]}
set +x

