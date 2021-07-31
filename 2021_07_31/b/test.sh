#!/bin/bash -eu

# Compile
make

PRE_IFS=$IFS
IFS=$'\n'

# Put data {input output}
input0="7777\n"
output0="Weak\n"

input1="0112\n"
output1="Strong"

input2="9012\n"
output2="Weak\n"

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
