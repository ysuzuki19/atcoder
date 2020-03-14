#!/bin/bash -eu

# Compile
make

PRE_IFS=$IFS
IFS=$'\n'
# Put data {input output}
input0="4 4 1 2 1 1 3 3 2 3 4 4 1"
output0="0 1 0 1"
input1="5 10 0 1 2 1 3 1 4 1 5 3 2 2 4 2 5 4 3 5 3 4 5"
output1="0 0 0 0 0"
input2="10 9 3 10 1 6 7 8 2 2 5 8 4 7 3 10 9 6 4 5 8 2 6 7 5 3 1"
output2="1 3 5 4 3 3 3 3 1 0"
inputs=(  ${input0}  ${input1}  ${input2})
outputs=(${output0} ${output1} ${output2})

if [ $# == 1 ]; then
	echo "== Testing with input" $1 " ====="
	echo -e ${inputs[$(($1-1))]}
	echo "------- Answer ------------"
	echo -e ${outputs[$(($1-1))]}
	echo "------- Result ------------"
	echo -e ${inputs[$(($1-1))]} | ./proj
	echo "==========================="
fi

## Test
if [ $# == 0 ]; then
	for ((idx=0; idx<${#inputs[@]}; idx++))
	do
		echo "== Testing with input" $((${idx}+1)) " ====="
		echo -e ${inputs[${idx}]}
		echo "------- Answer ------------"
		echo -e ${outputs[${idx}]}
		echo "------- Result ------------"
		echo -e ${inputs[${idx}]} | ./proj
	done
	echo "==========================="
fi
IFS=$PRE_IFS
