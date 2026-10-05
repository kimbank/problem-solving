n, m = tuple(map(int, input().split()))
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [
    list(0 for _ in range(m))
    for __ in range(n)
]

def in_range(x, y):
    return x >= 0 and x < n and y >= 0 and y < m

def can_go(x, y):
    if not in_range(x, y):
        return False
    if visited[x][y] == 1:
        return False
    if grid[x][y] == 0:
        return False
    return True

# dxs, dys = [-1, 0, 1, 0], [0, -1, 0, 1]
dxs, dys = [1, 0], [0, 1]

def dfs(x, y):
    for dx, dy in zip(dxs, dys):
        new_x, new_y = x + dx, y + dy

        if can_go(new_x, new_y):
            visited[new_x][new_y] = 1
            dfs(new_x, new_y)

dfs(0, 0)

print(
    visited[n - 1][m - 1]
)
