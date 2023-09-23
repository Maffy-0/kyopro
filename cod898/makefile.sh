for char in {a..e}
do
    filename="${char}.cpp"
    cp "../template.cpp" "$filename"
    echo "Created file: $filename"
done