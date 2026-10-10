str = input()

seen = {}

str_list = list(str)

for c in str_list:
    seen[c] = seen.get(c, 0) + 1

seen_sorted_list = sorted(seen.items(), key=lambda x: x[1])

if seen_sorted_list[0][1] == 1:
    print(seen_sorted_list[0][0])
else:
    print('None')
