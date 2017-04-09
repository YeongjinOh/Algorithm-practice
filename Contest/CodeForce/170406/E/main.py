import sys
s = raw_input()
m = input()
k = 1;
l = len(s)
for i in range(1,l-1) :
    k = (10*k)%m;
r = int(s[0])
for i in range(1,l-1) :
    r = ((r*10)+int(s[i]))%m;
res = r;
for i in range(0,l-2) :
    frt = int(s[i])
    r = (r + m - (k*frt)%m)%m;
    r = ((r*10)+(frt))%m;
    if int(s[i+1]) > 0 and res > r:
         res = r;
print(res)
