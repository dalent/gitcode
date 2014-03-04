#!/bin/bash - 
select opt in `seq 1 10`
do
	case $REPLY in
		1)
			echo one;;
		2)
			echo two;;
	esac
done
