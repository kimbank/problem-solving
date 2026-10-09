n, k = tuple(map(int, input().split()))
arr = list(map(int, input().split()))

seen = {}
ans = 0

for x in arr:
    seen[x] = seen.get(x, 0) + 1

for i in range(n):
    seen[arr[i]] -= 1

    for j in range(i):
        diff = k - arr[i] - arr[j]
        ans += seen.get(diff, 0)

print(ans)
