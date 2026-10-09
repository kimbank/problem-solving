n, k = tuple(map(int, input().split()))
arr = list(map(int, input().split()))

seen = {}
ans = 0

for x in arr:
    need = k - x
    ans += seen.get(need,0)
    seen[x] = seen.get(x,0) + 1

print(ans)
