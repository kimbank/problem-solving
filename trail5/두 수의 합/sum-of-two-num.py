n, k = map(int, input().split())
arr = list(map(int, input().split()))

ans = 0
counter = dict()

for num in arr:
    diff = k - num

    if diff in counter:
        ans += counter[diff]
    
    if num in counter:
        counter[num] += 1
    else:
        counter[num] = 1
    
print(ans)
