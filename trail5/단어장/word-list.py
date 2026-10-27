n = int(input())
words = [input() for _ in range(n)]

d = {}

for w in words:
    d[w] = d.get(w, 0) + 1

sorted_d = sorted(d.items(), key=lambda x: x[0])

for k, v in sorted_d:
    print(k, v)
