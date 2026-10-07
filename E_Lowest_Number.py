
n = int(input())
ar = list(map(int, input().split()))

mn = float('inf')
pos = 0

for i, val in enumerate(ar, 1):
    if val < mn:
        mn = min(mn, val)
        pos = i
        

print(f"{mn} {pos}")