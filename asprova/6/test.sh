#!/bin/bash -eu

# Compile
make

PRE_IFS=$IFS
IFS=$'\n'
# Put data {input output}
input0="HEADER 2 2 8 4 8\nMACHINE 0 5 2 2 5\nMACHINE 1 5 2 3 7\nBOM 0 0 43200 2000\nBOM 0 1 172800 2000\nBOM 1 0 129600 1000\nBOM 1 1 259200 1000\nCOMBI 0 0 0 0 0\nCOMBI 0 0 1 43200 1000\nCOMBI 0 1 0 43200 1000\nCOMBI 0 1 1 0 0\nCOMBI 1 0 0 0 0\nCOMBI 1 0 1 86400 1000\nCOMBI 1 1 0 86400 1000\nCOMBI 1 1 1 0 0\nORDER 0 0 0 864000 1 1 10000 86400\nORDER 1 0 0 864000 2 2 20000 86400\nORDER 2 0 0 864000 3 3 30000 86400\nORDER 3 0 0 864000 4 4 40000 86400\nORDER 4 1 0 864000 1 1 10000 86400\nORDER 5 1 0 864000 2 2 20000 86400\nORDER 6 1 0 864000 3 3 30000 86400\nORDER 7 1 0 864000 4 4 40000 86400"
output0="ORDER 0 0 1 0 43200\nORDER 1 0 2 0 43200\nORDER 2 1 3 0 172800\nORDER 3 0 4 43200 86400\nORDER 4 1 1 345600 604800\nORDER 5 1 2 345600 604800\nORDER 6 0 3 259200 388800\nORDER 7 0 4 518400 648000\nCOMBI 0 129600 172800\nCOMBI 1 172800 259200"
input1=""
output1=""
input2=""
output2=""

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
