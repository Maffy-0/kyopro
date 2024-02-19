sum=0
for i in {0000..0010}; do
    inp="in/${i}.txt"
    oup="out/${i}.txt"
    s=$(cargo run -r --bin tester ./problem.exe < $inp > $oup)
done
echo "finished";