n, k = tuple(map(int, input().split()))
arr = list(map(int, input().split()))

seen = {}
ans = 0

for x in arr:
    seen[x] = seen.get(x, 0) + 1

for i in range(n):
    right = arr[i]
    seen[right] -= 1
    for j in range(i):
        middle = arr[j]

        need = k - right - middle
        ans += seen.get(need, 0)

print(ans)
