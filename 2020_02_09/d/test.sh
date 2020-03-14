#!/bin/bash -eu

# Compile
make

PRE_IFS=$IFS
IFS=$'\n'
# Put data {input output}
input0="5 3 1 2 2 4 5"
output0="7.000000000000"
input1="4 1 6 6 6 6"
output1="3.500000000000"
input2="10 4 17 13 13 12 15 20 10 13 17 11"
output2="32.000000000000"

inputs=(  ${input0}  ${input1} ${input2})
outputs=(${output0} ${output1} ${output2})

echo $#

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
