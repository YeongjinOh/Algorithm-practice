#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define LEN 20
double c[LEN], r[LEN];
using namespace std;
int n, t;

double time(double c, double r, double s) {
    return s/r + ((double)t-s)/c;
}
double getDiff (double s) {
    double minTime = 1<<30;
    for (int i=0; i<n-1; ++i)
        minTime = min<double>(minTime, time(c[i],r[i],s));
    return minTime-time(c[n-1],r[n-1],s);
}
int main() {
    cin >> t >> n;
    for (int i=0; i<n; ++i)
        cin >> r[i] >> c[i];
    double l = 0, r = (double)t;
    for (int i=0; i<100; i++) {
        double t1 = (l*2+r)/3, t2=(l+2*r)/3;
        if (getDiff(t1) < getDiff(t2))
            l = t1;
        else
            r = t2;
    }
    double diff = getDiff(l);
    if (diff < 0) {
        cout << "The cheater can not win." << endl;
    } else {
        printf("The cheater can win by %d seconds with r = %.2lfkm and k = %.2lfkm.\n",(int)(diff*3600), l, (double)t-l);
    }
}
