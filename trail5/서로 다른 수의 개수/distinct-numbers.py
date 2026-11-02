n = int(input())
arr = list(map(int, input().split()))

cnt = 0
s = set()

for x in arr:
    if x in s:
        cnt += 1
    else:
        s.add(x)

print(n - cnt)
