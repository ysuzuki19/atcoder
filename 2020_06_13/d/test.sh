#!/bin/bash -eu

# Compile
make

PRE_IFS=$IFS
IFS=$'\n'
# Put data {input output}
input0="3\n1 2\n2 3\n3 4\n3\n1 1\n2 5\n3 5"
output0="0\n3\n3"
input1="15\n123 119\n129 120\n132 112\n126 109\n118 103\n115 109\n102 100\n130 120\n105 105\n132 115\n104 102\n107 107\n127 116\n121 104\n121 115\n8\n8 234\n9 244\n10 226\n11 227\n12 240\n13 237\n14 206\n15 227"
output1="256\n255\n250\n247\n255\n259\n223\n253"

inputs=(  ${input0}  ${input1})
outputs=(${output0} ${output1})

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
