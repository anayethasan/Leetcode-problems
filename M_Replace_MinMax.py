
n = int(input())
ar = list(map(int, input().split()))

mn = float('inf')
mx = 0

mx_pos = 0 
mn_pos = 0

for i, val in enumerate(ar):
    
    if(val < mn):
        mn = min(mn, val)
        mn_pos = i
    
    if(val > mx):
        mx = max(mx, val)
        mx_pos = i

ar[mn_pos], ar[mx_pos] = ar[mx_pos], ar[mn_pos]
    
print(*ar)
    
    