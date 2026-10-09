n, k = tuple(map(int, input().split()))
arr = list(map(int, input().split()))

seen = {}

for x in arr:
    seen[x] = seen.get(x, 0) + 1

key_desc = sorted(seen.items(), key=lambda x: x[0], reverse=True)
val_desc = sorted(key_desc, key=lambda x: x[1], reverse=True)

for i in range(k):
    print(val_desc[i][0], end=' ')
