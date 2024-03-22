#!/bin/bash

if [ $# -ne 2 ]; then
    exit 0
fi

first=$1
second=$2

for ((i = first; i <= second; i++)); do
    filename="${i}.cpp"
    cp "../../library/template.cpp" "$filename"
    echo "Created file: $filename"
done