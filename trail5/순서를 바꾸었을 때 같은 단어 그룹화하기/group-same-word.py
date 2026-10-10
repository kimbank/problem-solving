n = int(input())
words = [input() for _ in range(n)]

seen = {}
ans = 0

for w_str in words:
    w_list = list(w_str)
    w_list_sotred = sorted(w_list)

    w_str_sorted = ''.join(w_list_sotred)
    
    seen[w_str_sorted] = seen.get(w_str_sorted, 0) + 1
    if seen[w_str_sorted] > ans:
        ans = seen[w_str_sorted]

print(ans)
