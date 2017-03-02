#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
#define LEN 16
#define INF 987654321
int N;
double dist[LEN][LEN];
double cache[1<<LEN][LEN];
double best;
int cntTopDown, cntBottomUp;

double bottomUp(int cur, int visit) {
    cntBottomUp++;
    if (visit == (2<<N)-1)
        return 0.0;
    double &res = cache[visit][cur];
    if (res>0) return res;
    res = INF;
    for (int i=1; i<=N; i++) {
        if (visit & 1<<i) continue;
        res = min<double>(res, dist[cur][i] + bottomUp(i,visit+(1<<i)));
    }
    return res;
}

double topDown(int cur, int visit, double curLength) {
    cntTopDown++;
    if (visit == (2<<N)-1) {
        best = min<double>(best,curLength);
        return curLength;
    }
    double res = INF;
    for (int i=1; i<=N; ++i) {
        double nextLength = curLength + dist[cur][i];
        if (visit & (1<<i)) continue;
        if (nextLength > best) continue;
        res = min<double>(res, topDown(i, visit+(1<<i), nextLength));
    }
    return res;
}
int main() {
    int C;
    cin >> C;
    while(C--){
        cin >> N;
        for (int i=1; i<=N; ++i)
            for (int j=1; j<=N; ++j) {
                cin >> dist[i][j];
                dist[0][j] = 0;
            }
        memset(cache,0,sizeof(cache));
        best = INF;
        cntTopDown = 0;
        cntBottomUp = 0;
        printf("topDown:%.10lf with cnt:%d\n",topDown(0,1,0.0), cntTopDown);
        printf("bottomUp:%.10lf with cnt:%d\n",bottomUp(0,1), cntBottomUp);
    }
    return 0;
}
