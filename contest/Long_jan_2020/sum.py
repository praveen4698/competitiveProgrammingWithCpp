import math

t = int(input())
while t > 0:
    n = int(input())
    maxi = int(math.pow(10,n)) 
    a = int(input())
    s = a + 2*maxi
    print(s)
    b = int(input())
    print(maxi-b)
    c = int(input())
    print(maxi-c)
    x = int(input())
    t -= 1