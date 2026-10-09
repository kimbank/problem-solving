n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))
D = list(map(int, input().split()))

ab_sum = {}
cd_sum = {}

for i in range(n):
    for j in range(n):
        a = A[i]
        b = B[j]
        ab_sum[a+b] = ab_sum.get(a+b, 0) + 1

for i in range(n):
    for j in range(n):
        c = C[i]
        d = D[j]
        cd_sum[c+d] = cd_sum.get(c+d, 0) + 1

ans = 0

for ab_key in list(ab_sum.keys()):
    ans += ab_sum[ab_key] * cd_sum.get(-ab_key, 0)

print(ans)
