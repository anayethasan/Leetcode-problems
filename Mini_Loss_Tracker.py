n = int(input())
target = float(input())

cnt = n
total = 0

while n > 0:
    loss = float(input())
    total += loss
    n -= 1

avg = total / cnt

if target >= avg:
    print('PASS')
else:
    print('RETRY')