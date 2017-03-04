/////////////////////////////////////////////////////
// implement binary search with double type values
/////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define LEN 200
using namespace std;
// N <= 100 / N <= M <= 200 / distance <= 240.00
int C, N, M;
double pos[LEN];

// check if maximam distance of the closest two cameras is greater than or equal to dist
bool check(double dist) {
    // current camera position, number of camera set to some position
    double cur = pos[0];
    int num = 1;
    for (int i=1; i<M; ++i) {
        if (pos[i]-cur >= dist) {
            cur = pos[i];
            num++;
        }
    }
    return num >= N;
}
int main() {
    cin >> C;
    while (C--) {
        cin >> N >> M;
        double tmp;
        for (int i=0; i<M; ++i)
            cin >> pos[i];
        double l = 0.0, r = 240.1;
        int mid = (l+r)/2;
        while (r-l>0.001) {
            double mid = (l+r)/2;
            if (check(mid))
                l = mid;
            else
                r = mid;
        }
        printf("%.2lf\n",l);
    }
}
