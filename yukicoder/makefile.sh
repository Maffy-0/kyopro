#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <number>"
    exit 1
fi

number=$1

filename="${number}.cpp"
cp "../../library/template.cpp" "$filename"
echo "Created file: $filename"

code "$filename"
