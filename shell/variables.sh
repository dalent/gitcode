#!/bin/bash - 
echo <<EOF
$$ = pid
$? = exit status
$0 = call program name
$1 = first argument
...
$* = all the argument
$# = number of command 
shift command to shift command line arguments

EOF
echo ====pip====
echo \$\$
echo $$
echo ====arguments====
echo \$*
echo $*
echo ====numbeer====
echo \$#
echo $#
until [ $# -eq 0 ]
do
	echo $1
	shift 
done

