#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define LEN 500
#define INF 987654321
using namespace std;
int C, n, m;
int source, sink, node;
int c[LEN][LEN], f[LEN][LEN];
////////////////////////////////////////////////
//
// 적절히 유량 그래프로 변형하여 문제 풀기.
//
////////////////////////////////////////////////
int FordFulkerson() {
    /*
       for (int i=0; i<node; i++) {
       for (int j=0; j<node; j++) {
       printf("%d ", c[i][j]);
       }
       cout << endl;
       }
       */
    memset(f,0,sizeof(f));
    int totalFlow = 0;
    while(true) {
        vector<int> parent(node, -1);
        queue<int> q;
        q.push(source);
        parent[source] = source;
        while(!q.empty() && parent[sink] == -1) {
            int here = q.front(); q.pop();
            for (int there=0; there<node; there++) {
                if (parent[there] == -1 && c[here][there]-f[here][there] > 0) {
                    parent[there] = here;
                    q.push(there);
                }
            }
        }
        if (parent[sink] == -1) break;
        // calc minFlow
        int minFlow = INF;
        for (int here=sink; here!=source; here=parent[here]) {
            minFlow = min<int>(minFlow, c[parent[here]][here]-f[parent[here]][here]);
            //            printf("here:%d minf:%d\n", here, minFlow);
        }
        // update
        for (int here=sink; here!=source; here=parent[here]) {
            f[parent[here]][here] += minFlow;
            f[here][parent[here]] -= minFlow;
        }
        totalFlow += minFlow;
    }
    return totalFlow;
}

void solve() {
    memset(c,0,sizeof(c));
    cin >> n >> m;
    vector<int> score(n);
    for (int i=0; i<n; i++) scanf("%d", &score[i]);
    int maxScore = 0;
    for (int i=1; i<n; i++) maxScore = max<int>(maxScore, score[i]);
    // build network
    source = n;
    sink = n+1;
    node = n+2;
    int maxWin = 0;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        c[source][node] = 1;
        c[node][a] = INF;
        c[node][b] = INF;
        node++;
        if (a==0||b==0) maxWin++;
    }
    c[0][sink] = 0;
    for (int i=1; i<n; i++)
        c[i][sink] = score[0]-score[i]-1;
    // the number player-0 win
    for (int win=0; win<=maxWin; win++) {
        if (win > maxScore-score[0]) {
            int flow = FordFulkerson();
            if (flow == m) {
                printf("%d\n",score[0]+win);
                return;
            }
        }
        for (int i=0; i<n; i++) c[i][sink]++;
    }
    printf("-1\n");
}

int main() {
    cin >> C;
    while (C--) {
        solve();
    }
}
