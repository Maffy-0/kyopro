A, M, L, R = map(int, input().split())
l = (L + M - A) % M
if l == 0:
    left = L
else:
    left = L + M - l
r = (R + M - A) % M
right = R - r
ans = (right - left) // M
ans += 1
print(ans)