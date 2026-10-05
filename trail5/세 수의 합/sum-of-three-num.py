n, k = map(int, input().split())
arr = list(map(int, input().split()))

ans = 0

for i in range(n):
    right = arr[i]
    diff = k - right

    count = dict()

    for j in range(i):
        middle = arr[j]
        diff_diff = diff - middle

        if diff_diff in count:
            ans += count[diff_diff]
        
        if middle in count:
            count[middle] += 1
        else:
            count[middle] = 1

print(ans)
