#!/bin/bash - 
OPTIONS=("Hello" "Quit")
set -x
select opt in ${OPTIONS[@]}
do
	if [ $REPLY = "Quit" ]; then
		echo done
		exit
	elif [ $REPLY = "Hello" ]; then
		echo hello world
	else
		clear
		echo bad option
	fi
done
