#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
#define LEN 17
#define INF 987654321
int N;
double dist[LEN][LEN], minDist[LEN];
double cache[1<<LEN][LEN];
double best;
int cntTopDown, cntBottomUp, cntOptimized;
vector<int> neighbors[LEN];

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

// topdown에서는 DP를 섞어 쓰기가 힘들다!
// 현재 state(cur, visit)에서의 curLength가 실제 지나온 경로 (같은 visit set 내에서) 다를 수 있으므로
// 예를 들어, 같은 cur, visit에서 curLength가 10일 때 그 값을 DP에 저장해놓고, curLength가 5일 때 그대로 값을 쓰면 문제가 생긴다.
// 웬만하면 섞어쓰지 말자!!!

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
        // 1. 가지치기(pruning)
        if (nextLength > best) continue;
        res = min<double>(res, topDown(i, visit+(1<<i), nextLength));
    }
    return res;
}

// current p-a- ... -b-q
// but p-b- ... -a-q is smaller or equal to.
// then no more search
bool checkMoreSearch (vector<int> & path) {
    if (path.size() < 5) return true;
    int p = path[1], a = path[2];
    for (int i=3; i<path.size()-1; i++) {
        int b = path[i], q = path[i+1];
        if (dist[p][a] + dist[b][q] >= dist[p][b] + dist[a][q])
            return false;
    }
    return true;
}

bool checkAllVisit(vector<bool> & visit) {
    for (int i=0; i<visit.size(); ++i)
        if(!visit[i]) return false;
    return true;
}
double optimizedTopDown(vector<int> & path, vector<bool> & visit, double curLength) {
    cntOptimized++;
    if (checkAllVisit(visit)) {
        best = min<double>(best,curLength);
        return curLength;
    }
    if (!checkMoreSearch(path)) return INF;
    int cur = path.back();
    double res = INF;

    // check sum of min distance
    double minSum = 0.0;
    if (visit.size() != N+1)
        cout << "asdsad" << endl;
    for (int i=1; i<=N; ++i) {
        if (!visit[i]) {
            minSum += minDist[i];
        }
    }
    if (curLength + minSum > best)
        return INF;


    for (int i=0; i<neighbors[cur].size(); ++i) {
        int next = neighbors[cur][i];
        if (visit[next]) continue;
        if (best < curLength + dist[cur][next]) continue;
        path.push_back(next);
        visit[next] = true;
        res = min<double>(res, optimizedTopDown(path, visit, dist[cur][next] + curLength));
        visit[next] = false;
        path.pop_back();
    }
    return res;
}

int main() {
    int C;
    cin >> C;
    memset(dist,0,sizeof(dist));
    while(C--){
        cin >> N;
        for (int i=1; i<=N; ++i) {
            // initialize
            double minD = INF;
            vector<pair<double, int> > order;
            neighbors[i].clear();
            // get input
            for (int j=1; j<=N; ++j) {
                cin >> dist[i][j];
                if (i != j) {
                    minD = min<double>(minD, dist[i][j]);
                    order.push_back(make_pair(dist[i][j],j));
                }
            }
            // pre process
            sort(order.begin(),order.end());
            for (int j=0; j<order.size(); ++j)
                neighbors[i].push_back(order[j].second);
            minDist[i] = minD;
        }
        neighbors[0].clear();
        for (int i=1; i<=N; ++i)
            neighbors[0].push_back(i);

//        memset(cache,0,sizeof(cache));
        cntTopDown = 0;
        cntBottomUp = 0;
        vector<int> path;
        vector<bool> visit (N+1, false);
        visit[0] = true;
        path.push_back(0);
        best = INF;
        //printf("topDown:%.10lf \twith cnt:%d\n",topDown(0,1,0.0), cntTopDown);
//        printf("bottomUp:%.10lf \twith cnt:%d\n",bottomUp(0,1), cntBottomUp);
        best = INF;
//        printf("Opt-Topdown:%.10lf \twith cnt:%d\n",optimizedTopDown(path,visit,0.0), cntOptimized);
        printf("%.10lf\n",optimizedTopDown(path,visit,0.0));
    }
    return 0;
}
