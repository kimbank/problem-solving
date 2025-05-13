arr = []

for _ in range(4):
    arr.append(list(map(int, input().split())))

for _ in range(4):
    print(sum(arr[_]))
