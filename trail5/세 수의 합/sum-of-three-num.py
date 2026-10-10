n, k = tuple(map(int, input().split()))
arr = list(map(int, input().split()))

seen = {}
ans = 0

for num in arr:
    seen[num] = seen.get(num, 0) + 1

for i in range(n):
    right = arr[i]
    seen[right] -= 1
    for j in range(i):
        middle = arr[j]
        need = k - right - middle
        ans += seen.get(need, 0)

print(ans)
