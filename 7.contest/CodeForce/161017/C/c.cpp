#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long max (long long a, long long b) { return a>b? a: b;}
long long sum  (long long b, long long d, long long  s) {
    long long days = max(b, max(d,s));
    return (days-b) + (days-d) + (days-s);
}
int main () {
    long long b, d, s;
    scanf("%lld%lld%lld", &b, &d, &s);

    long long minsum = 2e18;
    long long cursum;
    long long curb, curd, curs;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            curb = b;
            curd = d;
            curs = s;
            if (i > 0)
                curb--;
            if (i > 1)
                curd--;
            if (j > 0)
                curb++;
            if (j > 1)
                curd++;
            cursum = sum(curb, curd, curs);
            if (minsum > cursum)
                minsum = cursum;
        }
    }

    printf("%lld\n", minsum);

    return 0;
}
