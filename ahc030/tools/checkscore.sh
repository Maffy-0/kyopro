sum=0
for i in {0000..0030}; do
    inp="in/${i}.txt"
    s=$(cargo run -r --bin tester ./problem.exe < $inp 2>&1 | grep -oP 'Score = \K\d+')
    echo Score $i = $s
    sum=$((sum + s))
done
echo Sum = $sum