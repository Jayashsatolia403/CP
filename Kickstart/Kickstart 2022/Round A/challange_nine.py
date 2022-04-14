T = int(input())


def check(st) :
 
    # Compute sum of digits
    n = len(st)
    digitSum = 0
     
    for i in range(0,n) :
        digitSum = digitSum + (int)(st[i])
 
    # Check if sum of digits
    # is divisible by 9.
    return (digitSum % 9 == 0)



for t in range(T):
    s = input()

    result = s + "99"

    for i in range(len(s)+1):
        for x in range(10):

            if i == 0 and x == 0:
                continue


            y = s[:i] + str(x) + s[i:]

            if (check(y)):
                if result > y:
                    result = y

    print("Case #{}: {}".format(t+1, result))