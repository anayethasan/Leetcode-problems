t = int(input())

yes_cnt, no_cnt = 0, 0
while t > 0:
    s = input()
    if s.lower() == 'yes':
        yes_cnt += 1
    else:
        no_cnt += 1
    t -= 1

print('ACCEPT' if yes_cnt >= no_cnt else 'REJECT')