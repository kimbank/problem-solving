n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))
D = list(map(int, input().split()))

ab_sum = {}
cd_sum = {}

# a + b = -(c + d)

for a in A:
    for b in B:
        ab_sum[a + b] = ab_sum.get(a + b, 0) + 1

for c in C:
    for d in D:
        cd_sum[c + d] = cd_sum.get(c + d, 0) + 1

ans = 0
for ab_key, ab_value in ab_sum.items():
    ans += ab_value * cd_sum.get(-ab_key, 0)

print(ans)
