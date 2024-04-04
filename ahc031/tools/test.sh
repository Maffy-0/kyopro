sum=0
for i in {0000..0010}; do
    inp="in/${i}.txt"
    oup="out/${i}.txt"
    p < $inp > $oup
done
for i in {0000..0010}; do
    inp="in/${i}.txt"
    oup="out/${i}.txt"
    s=$(cargo run -r --bin vis $inp $oup | grep -oP 'Score = \K\d+')
    echo Score $i = $s
    sum=$((sum + s))
done
echo Sum = $sum
