n = int(input())

while(n > 0):
    s = input()

    if '101' in s or '010' in s:
        print('Good')
    else:
        print('Bad')
    n -= 1
