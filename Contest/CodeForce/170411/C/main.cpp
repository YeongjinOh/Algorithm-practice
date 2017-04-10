#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
#define MAX 300005
#define INF 1234567890
int a[MAX];
int n, b, c;
vector<int> g[MAX];
int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; ++i)
        scanf("%d", &a[i]);
    for (int i=0; i<n-1; ++i) {
        scanf("%d%d", &b ,&c);
        g[b].push_back(c);
        g[c].push_back(b);
    }
    int maxNum = -INF, maxCnt = 0, maxIdx = -1;
    for (int i=1; i<=n; i++) {
        if (a[i] == maxNum) maxCnt++;
        if (a[i] > maxNum) {
            maxNum = a[i];
            maxIdx = i;
            maxCnt = 1;
        }
    }

    // maxNum or maxNum + 1
    if (maxCnt == 1) {
        queue<int> q;
        vector<int> dist(n+1, INF);
        vector<bool> visit(n+1, false);
        dist[maxIdx] = 0;
        visit[maxIdx] = true;
        q.push(maxIdx);

        while(!q.empty()) {
            int here = q.front(); q.pop();
            maxNum = max<int>(maxNum, a[here]+dist[here]);
            for (int i=0; i<g[here].size(); i++) {
                int there = g[here][i];
                if (!visit[there]) {
                    q.push(there);
                    visit[there] = true;
                    dist[there] = min<int>(2,dist[here] + 1);
                }
            }
        }
        printf("%d\n", maxNum);
        return 0;
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // IMPORTANT
        //
        // maxNum+1 or maxNum+2 인 case
        // max 가 여러개인 경우, 어떤 노드(root, max일 필요 없음) 를 기준으로, depth 1 이내에 max들이 뭉쳐있어야 한다.
        // -> 모든 노드에 대해 검사하면 됨. 그래봤자 O(|E|) == O(|V|)
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    } else {
        queue<int> q;
        vector<int> dist(n+1, INF);
        vector<bool> visit(n+1, false);
        dist[maxIdx] = 0;
        visit[maxIdx] = true;
        q.push(maxIdx);
        int cnt = 1, root = -1;

        while(!q.empty()) {
            int here = q.front(); q.pop();
            if (dist[here] > 2) break;
            for (int i=0; i<g[here].size(); i++) {
                int there = g[here][i];
                if (!visit[there]) {
                    if (dist[here] == 1 && a[there] == maxNum) {
                        root = here;
                        break;
                    }
                    q.push(there);
                    visit[there] = true;
                    dist[there] = dist[here] + 1;
                    if (dist[there] <= 2 && a[there] == maxNum)
                        cnt++;
                }
            }
            if (root >= 0)
                break;
        }
        if (root >= 0) {
            int cnt = a[root] == maxNum?1:0;
            for (int i=0; i<g[root].size(); i++) {
                int there = g[root][i];
                if (a[there] == maxNum)
                    cnt++;
            }
            if (cnt == maxCnt) {
                printf("%d\n", maxNum+1);
                return 0;
            } else {
                printf("%d\n", maxNum+2);
                return 0;
            }
        } else if (cnt == maxCnt) {
            printf("%d\n", maxNum+1);
            return 0;
        } else {
            printf("%d\n", maxNum+2);
            return 0;
        }
    }

    return 0;
}
