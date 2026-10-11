n, k = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]
points = [tuple(map(int, input().split())) for _ in range(k)]

from collections import deque

reached = {}
visited = [
    [0 for _ in range(n)]
    for __ in range(n)
]

def in_range(x, y):
    return x >= 0 and x < n and y >= 0 and y < n

def can_go(x, y):
    if not in_range(x, y):
        return False
    if visited[x][y] == 1:
        return False
    if grid[x][y] == 1:
        return False
    return True

def bfs(x, y):
    queue = deque()
    queue.append((x, y))
    visited[x][y] = 1
    reached[(x, y)] = 1

    while len(queue) > 0:
        cur_x, cur_y = queue.popleft()
        for dx, dy in zip([-1, 0, 1, 0], [0, -1, 0, 1]):
            new_x, new_y = cur_x + dx, cur_y + dy
            if can_go(new_x, new_y):
                visited[new_x][new_y] = 1
                reached[(new_x, new_y)] = 1
                queue.append((new_x, new_y))

for x, y in points:
    bfs(x - 1, y - 1)

print(len(reached))
