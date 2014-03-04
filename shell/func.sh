#!/bin/bash - 

function e {
	echo $1
}

f() {
	return `expr $1 + $2`
}

e Hello
f 2 3
total=$?
echo $total
