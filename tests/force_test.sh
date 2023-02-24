#!/bin/bash

#################
#### DEFINES ####
#################

RED="\033[31m"
GREEN="\033[32m"
NC="\033[0m"

push_swap="../push_swap"
checker="../checker"
path_program="./force/"
name_program="gen_num.py"
cache="cache"
instructions="instructions"
count=1000

###################
#### FUNCTIONS ####
###################

function	print_loading_bar()
{
	progress=$1
	echo -n "["
	for j in $(seq 1 $progress); do
		echo -ne "="
	done
	for j in $(seq 1 $((100-$progress))); do
		echo -ne " "
	done
	echo -n "]"

}

function	print_load()
{
	i=$1
	count=$2
	progress=$(($i * 100 / $count))
	echo -ne "\rProgress: "
	# print_loading_bar "$progress"
	echo -ne "$progress%\r"
}

function	print_result()
{
	ret=$1
	echo -e "\r\r"
	if [ $ret -eq 0 ];
	then
		echo -e "${GREEN}MEGA OK${NC}"
	else
		echo -e "${RED}MEGA KO${NC}"
	fi
}

function	is_acceptable()
{
	count_inst=$1
	count_arg=$2
	if [[ $count_arg -eq 500 && $count_inst -gt 7000 ]] || [[ count_arg -eq 3 && $count_inst -gt 3 ]] || [[ $count_arg -eq 5 && $count_inst -gt 12 ]]; then
		return 1
	fi
	return 0
}

function	is_optimized()
{
	ARG=$1
	instructions=$2
	count_inst=$(cat $instructions | wc -l)
	count_arg=$(echo $ARG | wc -w)
	is_acceptable $count_inst $count_arg
	return $?
}

#################
#### PROCESS ####
#################

ret=0
program=$path_program$name_program
echo "" > $cache
for i in $(seq 1 $count)
do
	ARG="$(echo $(python3 ./$program))"
	./$push_swap $ARG > $instructions
	cat $instructions | ./$checker $ARG >> $cache
	result=$?
	is_optimized "$ARG" "$instructions"
	result=$(($result+$?))
	if [ $result -ne 0 ];
	then
		ret=1
		echo -e "\n$ARG\n"
	fi
	print_load $i $count
done
print_result $ret
rm $instructions
