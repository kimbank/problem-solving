n, m = map(int, input().split())
arr = list(map(int, input().split()))
nums = list(map(int, input().split()))

# Please write your code here.

d = {}
for i in arr:
    if i in d:
        d[i] += 1
    else:
        d[i] = 1

for i in nums:
    if i in d:
        print(d[i], end=' ')
    else:
        print(0, end=' ')


