n,q = map(int, input().split())
ima = [1] * n
t = list(map(int,input().split()))
for i in t:
    if ima[i-1] == 1:
        ima[i-1] = 0
    else:
        ima[i-1] = 1
print(sum(ima))
