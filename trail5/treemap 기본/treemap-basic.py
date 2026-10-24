n = int(input())

cmd = []
k = []
v = []

for _ in range(n):
    line = input().split()
    cmd.append(line[0])
    if line[0] == "add":
        k.append(int(line[1]))
        v.append(int(line[2]))
    elif line[0] == "remove" or line[0] == "find":
        k.append(int(line[1]))
        v.append(0)
    else:
        k.append(0)
        v.append(0)

from sortedcontainers import SortedDict

sd = SortedDict()

for i in range(n):
    c = cmd[i]
    kk = k[i]
    vv = v[i]
    if c == "add":
        sd[kk] = vv
    elif c == "remove":
        sd.pop(kk)
    elif c == "find":
        print(sd[kk] if (kk in sd) else "None")
    elif c == "print_list":
        if len(sd) <= 0:
            print("None")
        
        vvs = list(map(str, sd.values()))
        print(" ".join(vvs))
