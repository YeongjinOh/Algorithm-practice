#include <iostream>
#include <cstdio>
using namespace std;
#define LEN 16
#define INF 987654321
// number of cities. smaller than or equal to 8
int N;
double dist[LEN][LEN];
double cache[LEN][1<<LEN];
bool done[LEN][1<<LEN];

double min(double a, double b) { return a>b?b:a;}
double getMin(int cur, int visit) {
    if (visit == (1<<N)-1)
        return 0;
    double &ret = cache[cur][visit];
    if (done[cur][visit]) return ret;
    ret = INF;
    for (int i=1; i<=N; i++) {
        if (visit & (1<<(i-1)))
            continue;
        ret = min(ret, dist[cur][i] + getMin(i, visit + (1<<(i-1))));
    }
    done[cur][visit] = true;
    return ret;
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
        memset(done,0,sizeof(done));
        printf("%.10lf\n",getMin(0,0));
    }
    return 0;
}
