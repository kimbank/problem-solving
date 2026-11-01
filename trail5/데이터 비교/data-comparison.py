n = int(input())
arr1 = list(map(int, input().split()))

m = int(input())
arr2 = list(map(int, input().split()))

s = set(arr1)

for x in arr2:
    if x in s:
        print(1, end=' ')
    else:
        print(0, end=' ')
