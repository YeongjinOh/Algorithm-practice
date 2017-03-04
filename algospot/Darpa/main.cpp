#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define LEN 200
using namespace std;
// N <= 100 / N <= M <= 200 / distance <= 24000
int C, N, M;
int pos[LEN];

// check if maximam distance of the closest two cameras is greater than or equal to dist
bool check(int dist) {
    // current camera position, number of camera set to some position
    int cur = pos[0], num = 1;
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
        for (int i=0; i<M; ++i) {
            cin >> tmp;
            /////////////////////////////////////////////////////////////////////////////
            // ** important **
            //
            // (int)(0.29*100) = 28
            // since 0.29*100 = 28.9999999...6
            // so, we need to check when trasforming from double type to integer type
            /////////////////////////////////////////////////////////////////////////////
            pos[i] = (tmp*100);
            if (tmp*100 - (double)pos[i] > 0.5) pos[i]++;
        }
        int l = 0, r = 250000;
        int mid = (l+r)/2;
        while (l!=r) {
            if (check(mid)) {
                l = mid;
                mid = (l+r+1)/2;
            } else {
                r = mid-1;
                mid = (l+r+1)/2;
            }
        }
        printf("%.2lf\n",(double)l/100);
    }
}
