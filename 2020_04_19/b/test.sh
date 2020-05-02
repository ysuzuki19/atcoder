#!/bin/bash -eu

# Compile
make

PRE_IFS=$IFS
IFS=$'\n'
# Put data {input output}
input0="41 2\n5 6"
output0="30"
input1="10 2\n5 6"
output1="-1"
input2="11 2\n5 6"
output2="0"
input3="314 15\n9 26 5 35 8 9 79 3 23 8 46 2 6 43 3"
output3="9"

inputs=(  ${input0}  ${input1}  ${input2}  ${input3})
outputs=(${output0} ${output1} ${output2} ${output3})

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
