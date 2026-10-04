n, k = map(int, input().split())
arr = list(map(int, input().split()))

# Please write your code here.

ans = 0
count = dict()

for i in range(len(arr)):
    diff = k - arr[i]

    ans_ans = 0
    count_count = dict()
    for j in range(i):
        diff_diff = diff - arr[j]

        if diff_diff in count_count:
            ans_ans += count_count[diff_diff]

        if arr[j] in count_count:
            count_count[arr[j]] += 1
        else:
            count_count[arr[j]] = 1

    ans += ans_ans

print(ans)
