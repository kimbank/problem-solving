n, m = map(int, input().split())

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

dp = [
    [0] * m
    for _ in range(n)
]

# 시작점
dp[0][0] = grid[0][0]

for i in range(n):
    for j in range(m):
        # 뱀이 있는 칸은 이동 불가능
        if grid[i][j] == 0:
            continue

        # 위쪽에서 내려오는 경우
        if i > 0 and dp[i - 1][j] == 1:
            dp[i][j] = 1

        # 왼쪽에서 오른쪽으로 오는 경우
        if j > 0 and dp[i][j - 1] == 1:
            dp[i][j] = 1

print(dp[n - 1][m - 1])
