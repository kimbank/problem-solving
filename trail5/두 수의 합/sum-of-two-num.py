n, k = tuple(map(int, input().split()))
arr = list(map(int, input().split()))

count = dict()
ans = 0

for i in range(len(arr)):
    right = arr[i]

    diff = k - right

    if diff in count:
        ans += count[diff]
    
    if right in count:
        count[right] += 1
    else:
        count[right] = 1

print(ans)
