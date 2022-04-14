t = int(input())

def lcs(X , Y):
    # find the length of the strings
    m = len(X)
    n = len(Y)
 
    # declaring the array for storing the dp values
    L = [[None]*(n+1) for i in range(m+1)]
 
    """Following steps build L[m+1][n+1] in bottom up fashion
    Note: L[i][j] contains length of LCS of X[0..i-1]
    and Y[0..j-1]"""
    for i in range(m+1):
        for j in range(n+1):
            if i == 0 or j == 0 :
                L[i][j] = 0
            elif X[i-1] == Y[j-1]:
                L[i][j] = L[i-1][j-1]+1
            else:
                L[i][j] = max(L[i-1][j] , L[i][j-1])
 
    # L[m][n] contains the length of LCS of X[0..n-1] & Y[0..m-1]
    return L[m][n]



    
for i in range(1, t+1):
    a = input()
    b = input()
    
    if len(a) == 0:
        print("Case #{}: {}".format(i, len(b)))
        continue
    elif len(b) == 0:
        print("Case #{}: {}".format(i, "IMPOSSIBLE"))
        continue


    # x = lcs(a, b) - len(a)

    x = lcs(a, b) - len(a)

    if (x == 0):
        print("Case #{}: {}".format(i, len(b)-len(a)))
    else:
        print("Case #{}: {}".format(i, "IMPOSSIBLE"))