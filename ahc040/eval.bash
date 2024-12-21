#!/bin/bash

sum=0
for i in {0000..0099}; do
    # s=$(cargo run -r --bin tester python a.py < in/${i}.txt 2>&1 | grep -oP 'Score = \K\d+')
    s=$(cargo run -r --bin tester ./a.out < in/${i}.txt 2>&1 | grep -oP 'Score = \K\d+')
    echo Score $i = $s
    sum=$((sum+s))
done
echo Sum = $sum
