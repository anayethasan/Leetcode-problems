if __name__ == '__main__':
    n = int(input())
    t = tuple(map(int, raw_input().split()))

    print(hash(t))