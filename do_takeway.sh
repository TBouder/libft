#! /bin/sh

LIB="../libft"
CC="gcc -w" # -Wall -Wextra -Werror"
FILES="*.c"
#MAIN="main_d.c"

$CC $FILES $MAIN -lft -L$LIB -I $LIB
if [ "$?" -eq "0" ]
then
	if [ "$#" -ge "1" ] && [ "$1" == "diff" ]
	then
		./a.out | sed 's/^[sm]//g' | awk '(NR % 3 == 1){std=$0};(NR % 3 == 2){min=$0};(NR % 3 == 0){if (std != min)print std"\n"min"\n"$0}' | head -30
	else
		./a.out | head -30
	fi
fi
