#!/bin/bash

for i in {0000..0099}; do
    echo $i
    cargo run -r --bin tester ./a.out < in/${i}.txt > out/${i}.txt
done
