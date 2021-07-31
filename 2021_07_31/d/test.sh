#!/bin/bash -eu

# Compile
make

PRE_IFS=$IFS
IFS=$'\n'

# Put data {input output}
input0="5\n1 3\n1 5\n3\n2 2\n3"
output0="3\n7"

input1="6\n1 1000000000\n2 1000000000\n2 1000000000\n2 1000000000\n2 1000000000\n3"
output1="5000000000"

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
