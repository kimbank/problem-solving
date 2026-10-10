n = int(input())
points = [
    tuple(map(int, input().split()))
    for _ in range(n)
]

ans_dict = {}

for x, y in points:
    if x in ans_dict:
        ans_dict[x] = min(ans_dict[x], y)
    else:
        ans_dict[x] = y

print(sum(ans_dict.values()))
