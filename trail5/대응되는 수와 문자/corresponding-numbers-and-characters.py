n, m = map(int, input().split())

arr = list()
d = dict()

for _ in range(n):
    word = input()

    arr.append(word)
    d[word] = len(arr)

for _ in range(m):
    q = input()

    if q in d:
        print(d[q])
    else:
        print(arr[int(q) - 1])
