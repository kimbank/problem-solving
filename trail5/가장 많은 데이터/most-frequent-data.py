n = int(input())
words = [input() for _ in range(n)]

# Please write your code here.

d = dict()
max = 0

for w in words:
    if w in d:
        d[w] += 1
        if d[w] > max:
            max = d[w]
    else:
        d[w] = 1
        if d[w] > max:
            max = d[w]

print(max)
