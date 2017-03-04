#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define LEN 100

using namespace std;
int C, N;
double pos[LEN][2];

double distance (double x1, double x2, double y1, double y2) {
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}
bool check(double dist) {
    // grouping
    int parent[LEN];
    for (int i=0; i<N; i++)
        parent[i] = i;

    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            if (distance(pos[i][0],pos[j][0],pos[i][1],pos[j][1]) <= dist) {
                // find j-th root
                int jRoot = parent[j], iRoot = parent[i];
                while (jRoot != parent[jRoot]) { jRoot = parent[jRoot]; }
                while (iRoot != parent[iRoot]) { iRoot = parent[iRoot]; }
                parent[jRoot] = iRoot;
            }
        }
    }
    int root = parent[0];
    while(parent[root] != root) { root = parent[root];}
    for (int i=1; i<N; i++) {
        int curRoot = parent[i];
        while(parent[curRoot] != curRoot) { curRoot = parent[curRoot]; }
        if (root != curRoot) return false;
    }
    return true;
}
int main() {
    cin >> C;
    while (C--) {
        cin >> N;
        for (int i=0; i<N; i++)
            cin >> pos[i][0] >> pos[i][1];
        double l=0.0, r = 2000.0;
        while(r-l > 0.00005) {
            double mid = (l+r)/2;
            if (check(mid)) r = mid;
            else l = mid;
        }
        printf("%.2lf\n",r);
    }
}
