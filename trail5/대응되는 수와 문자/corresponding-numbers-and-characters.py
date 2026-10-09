n, m = tuple(map(int, input().split()))

words = [
    input()
    for _ in range(n)
]

queries = [
    input()
    for _ in range(m)
]

l = []
d = {}

for w in words:
    l.append(w)
    d[w] = len(l)

for q in queries:
    if q.isdigit():
        print(l[int(q) - 1])
    else:
        print(d[q])
