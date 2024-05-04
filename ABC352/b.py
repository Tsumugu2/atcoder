s = str(input())
t = str(input())
ans = 0
a = []
for i in range(len(t)):
    if s[ans] == t[i]:
        ans += 1
        a.append(i+1)
    if ans == len(s):
        print(*a)
        exit()
