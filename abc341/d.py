def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

def count_divisible(n, m, x):
    return x // n + x // m - x // lcm(n, m) - x // lcm(n, m)

def kth_number(n, m, k):
    low = min(n, m)
    high = max(n, m) * k

    while low < high:
        mid = (low + high) // 2
        if count_divisible(n, m, mid) < k:
            low = mid + 1
        else:
            high = mid

    return low

N, M, K = map(int, input().split())

result = kth_number(N, M, K)
print(result)