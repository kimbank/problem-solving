n, m = map(int, input().split())

# Note: Using 1-based indexing for words as per C++ code
words = [""] + [input() for _ in range(n)]
queries = [input() for _ in range(m)]

# Please write your code here.
l = list()
d = dict()

for w in words:
    d[w] = len(l)
    l.append(w)

for q in queries:
    if q in d:
        print(d[q])
    else:
        print(l[int(q)])
