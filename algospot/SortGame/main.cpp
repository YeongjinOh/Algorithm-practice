//////////////////////////////////////////////////////////////////////////
//
// Case가 1000개이므로, 한 번에 distance를 구해두고 시작.
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

#define LEN 8
using namespace std;
int C;

/////////////////////////////////////////////////////////////////////
//
// IMPORTANT
//
// C++ STL의 vector에는 대소 비교가 구현되어 있기 때문에,
// 별도의 구현을 하지 않아도 map의 키로 사용 가능.
//
/////////////////////////////////////////////////////////////////////
map<vector<int>, int> dist;

void bfs() {
    vector<int> root (8);
    for (int i=1; i<=LEN; i++)
        root[i-1] = i;
    queue<vector<int> > q;
    q.push(root);
    dist[root] = 0;
    while (!q.empty()) {
        vector<int> here = q.front(); q.pop();
        int distHere = dist[here];
        for (int end=2; end<=LEN; end++) {
            for (int begin=0; begin+2 <= end; begin++) {
                reverse(here.begin()+begin, here.begin()+end);
                if (dist.count(here) == 0) {
                    dist[here] = distHere+1;
                    q.push(here);
                }
                reverse(here.begin()+begin, here.begin()+end);
            }
        }
    }
}

void solve() {
    int n, a;
    cin >> n;
    // get input order
    vector<int> num(n), order(n);
    vector<bool> visit(n,false);
    for (int i=0; i<n; i++)
        cin >> num[i];
    for (int i=0; i<n; i++) {
        int minNum = 987654321, minIdx = -1;
        for (int j=0; j<n; j++) {
            if (!visit[j] && minNum > num[j]) {
                minNum = num[j];
                minIdx = j;
            }
        }
        visit[minIdx] = true;
        order[minIdx] = i+1;
    }
    for (int i=n; i<LEN; i++)
        order.push_back(i+1);
    // get minimal distance
    int ans = dist[order];
    cout << ans << endl;
}

int main() {
    bfs();
    cin >> C;
    while (C--) {
        solve();
    }
}
