n = int(input())
arr = list(map(int, input().split()))

from sortedcontainers import SortedDict

sd = SortedDict()

for i in range(n):
    x = arr[i]
    if x not in sd:
        sd[x] = i + 1

for k, v in sd.items():
    print(k, v)
