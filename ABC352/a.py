n,x,y,z = map(int, input().split())
if x > y:
    x,y = y,x
for i in range(x,y+1):
    if i == z:
        print("Yes")
        exit()
print("No")

