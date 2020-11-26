def func(a,b):
    if a == 0:
        return b
    else:
        return func(b%a,a)

a, b = map(int,input().split())
n = func(a,b)
print(a*b//n)

