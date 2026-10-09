n, k = map(int, input().split())
arr = list(map(int, input().split()))

count = {}

for x in arr:
    count[x] = count.get(x, 0) + 1

result = dict(sorted(count.items(), key=lambda x: x[0], reverse=True))
# print(result)
result2 = dict(sorted(result.items(), key=lambda x: x[1], reverse=True))
# print(result2)

anss = list(result2.keys())
for i in range(k):
    print(anss[i], end=' ')
