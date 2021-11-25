for T in range(int(input())):
    
    m,n = map(int, input().split())

    if m==1 and n==1:
        print(0)
    elif n==1 or m==1:
        print(1)
    else:
        print(2)