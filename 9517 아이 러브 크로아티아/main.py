K = int(input())
N = int(input())

time=180+30
current=0
# result=K+800000000000000-1
result = K-1

for i in range(N):
    a,b = input().split()
    a = int(a)

    # print(current, result+1)

    if(b=='T'):
        current += a
    elif b=='N' or b=='P':
        current+=a

    if (current >= time):
        break
    if b=='T':
        result+=1

print(result%8+1)