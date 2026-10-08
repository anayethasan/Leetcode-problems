x, min_v, max_v = map(float, input().split())

norm = (x - min_v) / (max_v - min_v)
print(f'{norm:.2f}')