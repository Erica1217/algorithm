n = int(input())
check = [ 0 for i in range(2010)]
data = list(map(int,input().split()))
for i in range(n):
    check[data[i]+1000]+=1

for i in range(2010):
    if check[i]>0:
        print(i-1000)
