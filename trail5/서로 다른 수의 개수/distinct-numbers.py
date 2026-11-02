n = int(input())
arr = list(map(int, input().split()))

s = set()

for x in arr:
    s.add(x)

print(len(s))
