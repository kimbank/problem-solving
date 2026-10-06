n, m = map(int, input().split())
arr = list(map(int, input().split()))
queries = list(map(int, input().split()))

d = dict()

for num in arr:
    if num in d:
        d[num] += 1
    else:
        d[num] = 1

for q in queries:
    if q in d:
        print(d[q], end=' ')
    else:
        print(0, end=' ')
