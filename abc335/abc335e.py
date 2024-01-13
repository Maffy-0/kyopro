def max_score(N, M, values, edges):
    graph = {i: [] for i in range(1, N + 1)}

    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    dp = [0] * (N + 1)

    for u in range(1, N + 1):
        for v in graph[u]:
            if values[v - 1] > values[u - 1]:
                dp[v] = max(dp[v], dp[u] + 1)

    return max(dp)

# 入力例
N = int(input())
M = int(input())
values = list(map(int, input().split()))
edges = [tuple(map(int, input().split())) for _ in range(M)]

result = max_score(N, M, values, edges)
print(result)
