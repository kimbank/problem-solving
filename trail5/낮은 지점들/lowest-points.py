n = int(input())
points = [tuple(map(int, input().split())) for _ in range(n)]

d = {}

for x, y in points:
    if x in d:
        if d[x] > y:
            d[x] = y
    else:
        d[x] = y

ans = sum(d.values())
print(ans)
