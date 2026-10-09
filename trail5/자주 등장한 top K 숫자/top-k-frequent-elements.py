n, k = map(int, input().split())
arr = list(map(int, input().split()))

count = {}

for x in arr:
    count[x] = count.get(x, 0) + 1

count = dict(sorted(count.items(), key=lambda x: x[0], reverse=True))
new_arr = sorted(count.items(), key=lambda x: x[1], reverse=True)

for i in range(k):
    print(new_arr[i][0], end=' ')
