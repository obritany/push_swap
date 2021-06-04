#!/bin/bash
# To get "shuf" command: brew install coreutils

#SETUP
TESTS=100
ARG_LEN=100
# CHECKER=./checker/checker
CHECKER=./checker_mac

echo -e "\033[1;32mStarting $TESTS tests with $ARG_LEN arguments\033[0m"
max=0
maxARG=""
for ((count = 0; count < $TESTS; count++))
do
	echo -e -n "\r$((count + 1)) "

	ARG=$(shuf -i 1-$ARG_LEN -n $ARG_LEN | tr '\n' ' ')

	if ./push_swap $ARG | $CHECKER $ARG | grep -q 'KO'; then
		echo -e "\033[1;31mKO $ARG\033[0m"
	fi

	temp=$(./push_swap $ARG | wc -l | tr -d ' ')

	if (($temp \> $max));
	then
		max=$temp
		maxARG=$ARG
	fi
done

echo
echo "Done!"
echo -e "\033[1;36mMax opertaions: $max\033[0m"
echo "With arguments: $maxARG"