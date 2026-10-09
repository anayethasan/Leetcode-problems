n, m = map(int, input().split())

ar = list(map(int, input().split()))

a = set(map(int, input().split()))
b = set(map(int, input().split()))

flag = 0

for val in ar:
    if val in a:
        flag += 1
    elif val in b:
        flag -= 1
        
print(flag if 1 else -1)