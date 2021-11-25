def is_palindrome(s):

    n = len(s)
    
    for i in range(n//2):
        if s[i] != s[n-i-1]:
            return False
    
    return True


for t in range(int(input())):
    len_arr = int(input())
    arr = list(map(int, input().split()))

    if is_palindrome(arr):
        print("YES")
    else:
        done = False

        for element in arr:
            array_copy = list(arr)
            array_copy = list(filter((element).__ne__, array_copy))

            if is_palindrome(array_copy):
                print("YES")
                done = True
                break

        if not done:
            print("NO")
