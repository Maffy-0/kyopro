#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <number>"
    exit 1
fi

number=$1
padded_number=$(printf "%03d" "$number")

dirname="abc${padded_number}"
mkdir "$dirname"
cd "$dirname"
for char in {a..f}
do
    filename="abc${padded_number}${char}.cpp"
    cp "../atcoder.cpp" "$filename"
    echo "Created file: $filename"
done

cd "../"
