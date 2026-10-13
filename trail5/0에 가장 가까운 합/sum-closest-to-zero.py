n = int(input())
a = list(map(int, input().split()))

arr = [0] + sorted(a)

ans = 10**10

j = n
for i in range(1, n + 1):
    if i < j:
        ans = min(ans, abs(arr[i] + arr[j]))

    while i < j - 1 and arr[i] + arr[j] > 0:
        j -= 1
        ans = min(ans, abs(arr[i] + arr[j]))

print(ans)
