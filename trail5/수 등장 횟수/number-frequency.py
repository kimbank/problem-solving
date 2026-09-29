n, m = map(int, input().split())
arr = list(map(int, input().split()))
nums = list(map(int, input().split()))

# Please write your code here.

d = dict()

for i in arr:
    if i not in d:
        d[i] = 1
    else:
        d[i] += 1

for i in nums:
    if i not in d:
        print(0, end=' ')
    else:
        print(d[i], end=' ')
