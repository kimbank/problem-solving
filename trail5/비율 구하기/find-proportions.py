n = int(input())
words = [input() for _ in range(n)]

from sortedcontainers import SortedDict

sd = SortedDict()

for w in words:
    sd[w] = sd.get(w, 0) + 1

for k, v in sd.items():
    print(f"{k} {(v / n) * 100:.4f}")
