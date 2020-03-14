#!/bin/bash -eu

# Compile
make

PRE_IFS=$IFS
IFS=$'\n'
# Put data {input output}
input0="84 97 66 79 89 11 61 59 7 7 89 7 87 79 24 84 30"
output0="Yes"
input1="41 7 46 26 89 2 78 92 8 5 6 45 16 57 17"
output1="No"
input2="60 88 34 92 41 43 65 73 48 10 60 43 88 11 48 73 65 41 92 34"
output2="Yes"
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
