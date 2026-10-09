n, k = map(int, input().split())
arr = list(map(int, input().split()))

count = {}

for x in arr:
    count[x] = count.get(x, 0) + 1

new_arr = [
    [value, key]
    for key, value in count.items()
]
new_arr = sorted(new_arr, reverse=True)

for i in range(k):
    print(new_arr[i][1], end=' ')
