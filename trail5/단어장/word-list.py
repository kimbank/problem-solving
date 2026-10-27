n = int(input())
words = [input() for _ in range(n)]

from sortedcontainers import SortedDict

sd = SortedDict()

for w in words:
    if w in sd:
        sd[w] += 1
    else:
        sd[w] = 1

for k, v in sd.items():
    print(k, v)
