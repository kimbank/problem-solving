n = int(input())
commands = []
x = []
for _ in range(n):
    cmd, val = input().split()
    commands.append(cmd)
    x.append(int(val))

s = set()

for cmd, val in zip(commands, x):
    if cmd == "find":
        print("true" if val in s else "false")
    elif cmd == "add":
        s.add(val)
    elif cmd == "remove":
        s.remove(val)
