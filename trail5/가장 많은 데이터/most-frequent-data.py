n = int(input())

d = dict()

ans = 0
for _ in range(n):
    word = input()

    if word in d:
        d[word] += 1
    else:
        d[word] = 1
    
    if d[word] > ans:
        ans = d[word]

print(ans)
