s = set(input())


if len(s) < 4:
    if (len(s) == 3):
        print(1)
    else:
        print(0)
else:
    print(len(s)-4)