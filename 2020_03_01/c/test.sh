#!/bin/bash -eu

# Compile
make

PRE_IFS=$IFS
IFS=$'\n'
# Put data {input output}
input0="3 3 1 7 3 2 1 7"
output0="702"
input1="3 2 2 1 2 3"
output1="-1"
input2="3 1 1 0"
output2="-1"
inputs=(  ${input0}  ${input1}  ${input2})
outputs=(${output0} ${output1} ${output2})

if [ $# == 1 ]; then
	echo "== Testing with input" $1 " ====="
	echo -e ${inputs[$1]}
	echo "------- Answer ------------"
	echo -e ${outputs[$1]}
	echo "------- Result ------------"
	echo -e ${inputs[$1]} | ./proj
	echo "==========================="
fi

## Test
if [ $# == 0 ]; then
	for ((idx=0; idx<${#inputs[@]}; idx++))
	do
		echo "== Testing with input" ${idx} " ====="
		echo -e ${inputs[${idx}]}
		echo "------- Answer ------------"
		echo -e ${outputs[${idx}]}
		echo "------- Result ------------"
		echo -e ${inputs[${idx}]} | ./proj
	done
	echo "==========================="
fi
IFS=$PRE_IFS
