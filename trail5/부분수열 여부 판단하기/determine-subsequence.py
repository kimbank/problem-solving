n, m = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

j = 0

for i in range(n):
    if j < m and A[i] == B[j]:
        j += 1

if j == m:
    print('Yes')
else:
    print("No")
