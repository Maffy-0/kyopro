import random

# 出力ファイル名
output_file = "random_numbers.txt"

# 出力個数
count = 200000

# ランダムな整数の範囲
min_val = 0
max_val = 10000000

# ランダムな整数を生成
random_numbers = [str(random.randint(min_val, max_val)) for _ in range(count)]

# ファイルに書き込み
with open(output_file, "w") as f:
    f.write(f"{count}\n")  # 最初の整数
    f.write(" ".join(random_numbers))  # 空白区切りのランダム整数
