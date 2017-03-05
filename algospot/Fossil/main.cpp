#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define LEN 100
using namespace std;
int C, n, m;
double hull1[LEN][2], hull2[LEN][2];

struct point {
    double x;
    double y;
};

// return negative value if no intersect
double getIntersect (double x) {
    double y1min = 100, y1max = 0, y2min = 100, y2max = 0;
    for (int i=0; i<n; i++) {
        double x1 = hull1[i%n][0], y1 = hull1[i%n][1], x2 = hull1[(i+1)%n][0], y2 = hull1[(i+1)%n][1];
        if (x1 == x2) continue;
        if ((x1 <= x && x <= x2) || (x2 <= x && x <= x1)) {
            double y = (x-x1)*(y2-y1)/(x2-x1)+y1;
            y1min = min<double> (y1min, y);
            y1max = max<double> (y1max, y);
        }
    }
    for (int i=0; i<m; i++) {
        double x1 = hull2[i%m][0], y1 = hull2[i%m][1], x2 = hull2[(i+1)%m][0], y2 = hull2[(i+1)%m][1];
        if (x1 == x2) continue;
        if ((x1 <= x && x <= x2) || (x2 <= x && x <= x1)) {
            double y = (x-x1)*(y2-y1)/(x2-x1)+y1;
            y2min = min<double> (y2min, y);
            y2max = max<double> (y2max, y);
        }
    }
    // if intersect
    return min(y1max, y2max) - max(y1min, y2min);
}
int main() {
    cin >> C;
    while (C--) {
        // get input
        cin >> n >> m;
        for (int i=0; i<n; ++i)
            cin >> hull1[i][0] >> hull1[i][1];
        for (int i=0; i<m; ++i)
            cin >> hull2[i][0] >> hull2[i][1];

        // check range
        double x1min = 100, x1max = 0, x2min = 100, x2max = 0;
        for (int i=0; i<n; i++) {
            x1min = min<double>(x1min, hull1[i][0]);
            x1max = max<double>(x1max, hull1[i][0]);
        }
        for (int i=0; i<m; i++) {
            x2min = min<double>(x2min, hull2[i][0]);
            x2max = max<double>(x2max, hull2[i][0]);
        }
        double l = max<double>(x1min, x2min), r = min<double>(x1max, x2max);
        if (l > r) {
            printf("%.6lf\n",0.0);
            return 0;
        }
        for (int i=0; i<100; i++) {
            double l1 = (2*l+r)/3.0, l2=(l+2*r)/3.0;
            if (getIntersect(l1) < getIntersect(l2))
                l = l1;
            else
                r = l2;
        }
        printf("%.10lf\n", max<double>(0.0,getIntersect(r)));
    }
}
