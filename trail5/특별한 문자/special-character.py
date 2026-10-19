word = input()

seen = {}

for c in word:
    seen[c] = seen.get(c, 0) + 1

ans = 'None'
for k, v in seen.items():
    if v == 1:
        ans = k
        break

print(ans)
