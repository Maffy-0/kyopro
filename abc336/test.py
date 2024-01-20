def is_harshad(number):
    # 数字の各桁の和を計算
    digit_sum = sum(int(digit) for digit in str(number))
    
    # ハーシャッド数かどうかを判定
    return number % digit_sum == 0

def write_to_file(filename, numbers):
    with open(filename, 'a') as file:
        for number in numbers:
            file.write(str(number) + '\n')

def generate_and_write_harshad_numbers_up_to_n(n, filename):
    with open(filename, 'w') as file:
        for number in range(1, n + 1):
            if is_harshad(number):
                file.write(str(number) + '\n')

if __name__ == "__main__":
    N = int(input("Nを入力してください: "))
    filename = "harshad_numbers.txt"
    
    generate_and_write_harshad_numbers_up_to_n(N, filename)
    
    print(f"{N}以下のハーシャッド数を {filename} に出力しました。")
