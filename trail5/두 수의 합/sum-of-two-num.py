n, k = map(int, input().split())
arr = list(map(int, input().split()))

d = dict()

for a in arr:
    if a in d:
        d[a] += 1
    else:
        d[a] = 1

d_keys = d.keys()
d_keys = list(d_keys)
d_keys.sort()

ans_cnt = 0
for current in d_keys:
    target = k - current
    if (target in d):
        current_cnt = d[current]
        target_cnt = d[target]
        if (target == current):
            ans_cnt += int((target_cnt * (target_cnt - 1)) / 2)
        elif (target > current):
            ans_cnt += target_cnt * current_cnt

print(ans_cnt)
