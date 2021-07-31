#!/bin/bash -eu

# Compile
make

PRE_IFS=$IFS
IFS=$'\n'

# Put data {input output}
input0="50 50\n"
output0="Alloy\n"

input1="100 0\n"
output1="Gold"

input2="0 100\n"
output2="Silver\n"

input3="100 2\n"
output3="Alloy\n"

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
