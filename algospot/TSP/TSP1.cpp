#include <iostream>
#include <cstdio>
using namespace std;

#define INF 987654321;
// number of cities. smaller than or equal to 8
int N;
double dist[8][8];
bool visit[8];
double min(double a, double b) { return a>b?b:a;}
double getMin(int cur, int n) {
    double ret = INF;
    if (n == N)
        return 0;
    for (int i=0; i<N; i++) {
        if (visit[i])
            continue;
        visit[i] = true;
        ret = min(ret, dist[cur][i] + getMin(i, n+1));
        visit[i] = false;

    }
    return ret;
}
int main() {
    int C;
    cin >> C;
    while(C--){
        cin >> N;
        for (int i=0; i<N; ++i)
            for (int j=0; j<N; ++j) {
                cin >> dist[i][j];
            }
        for (int i=0; i<N; ++i)
            visit[i] = false;
        double ret = INF;
        for (int i=0; i<N; ++i) {
            visit[i] = true;
            ret = min(ret, getMin(i,1));
            visit[i] = false;
        }
        printf("%.10lf\n",ret);
    }
    return 0;
}
