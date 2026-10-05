n, k = map(int, input().split())
arr = list(map(int, input().split()))

ans = 0
count = dict()


for elem in arr:
    if elem in count:
        count[elem] += 1
    else:
        count[elem] = 1


for i in range(n):
    right = arr[i]

    count[right] -= 1

    for j in range(i):
        middle = arr[j]
        
        diff = k - right - middle

        if diff in count:
            ans += count[diff]

print(ans)
