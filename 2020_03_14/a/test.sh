#!/bin/bash -eu

# Compile
make

PRE_IFS=$IFS
IFS=$'\n'
# Put data {input output}
input0="6"
output0="2"
input1="27"
output1="5"
inputs=(  ${input0}  ${input1})
outputs=(${output0} ${output1})

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
