#!/bin/bash -eu

# Compile
make

PRE_IFS=$IFS
IFS=$'\n'
# Put data {input output}
input0="3 4 3\n1 3 3 100\n1 2 2 10\n2 3 2 10"
output0="110"
input1="4 6 10\n2 4 1 86568\n1 4 0 90629\n2 3 0 90310\n3 4 1 29211\n3 4 3 78537\n3 4 2 8580\n1 2 1 96263\n1 4 2 2156\n1 2 0 94325\n1 4 3 94328"
output1="357500"
input2="10 10 1\n1 10 9 1"
output2="1"

inputs=(  ${input0}  ${input1}  ${input2})
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
