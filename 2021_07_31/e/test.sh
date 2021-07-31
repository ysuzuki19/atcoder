#!/bin/bash -eu

# Compile
make

PRE_IFS=$IFS
IFS=$'\n'

# Put data {input output}
input0="3 1 4\n2 3"
output0="4"

input1="3 3 3\n1 2\n1 3\n2 3"
output1="0"

input2="5 3 100\n1 2\n4 5\n2 3"
output2="428417047"

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
