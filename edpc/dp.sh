#!/bin/bash

for char in {a..z}
do
    filename="dp_${char}.cpp"
    cp "../atcoder.cpp" "$filename"
    echo "Created file: $filename"
done