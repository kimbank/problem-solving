from collections import deque

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

def bfs(x, y):
    queue = deque()

    queue.append((x, y))

    dxs = [-1, 0, 1, 0]
    dys = [0, -1, 0, 1]

    while(len(queue) > 0):
        cur_x, cur_y = queue.popleft()

        if cur_x == n - 1 and cur_y == m - 1:
            return 1

        for dx, dy in zip(dxs, dys):
            new_x, new_y = cur_x + dx, cur_y + dy

            if can_go(new_x, new_y):
                visited[new_x][new_y] = 1
                queue.append((new_x, new_y))
    
    return visited[n - 1][m - 1]

print(bfs(0, 0))
