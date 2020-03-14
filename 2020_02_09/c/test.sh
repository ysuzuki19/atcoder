#!/bin/bash -eu

# Compile
make

PRE_IFS=$IFS
IFS=$'\n'
# Put data {input output}
input0="5 2 6 1 4 5"
output0="YES"
input1="6 4 1 3 1 6 2"
output1="NO"
input2="2 10000000 10000000"
output2="NO"

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
