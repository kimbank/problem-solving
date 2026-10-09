n, k = map(int, input().split())
arr = list(map(int, input().split()))

count = {}

for x in arr:
    count[x] = count.get(x, 0) + 1

def get_key(x: list):
    return x[0]
def get_value(x: list):
    return x[1]

# sort by key desc
key_desc = sorted(count.items(), key=get_key, reverse=True)

# sort by value desc
result = sorted(key_desc, key=get_value, reverse=True)

for i in range(k):
    print(result[i][0], end=' ')