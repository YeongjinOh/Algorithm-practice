#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int C;

int dist[1<<24];

// move(0, 2, 0, 1) -> 00 00 00 ... 00 00 -> 00 00 00 ... 01 00
int move(int comb, int topNum, int from, int to) {
    topNum--;
    return comb ^ ((from^to) << (2*topNum));
}

vector<int> getTopNumber(int comb) {
    vector<int> topNum;
    for (int i=0; i<4; i++)
        topNum.push_back(16);
    for (int i=1; i<=12; i++) {
        int stick = comb & 3;
        topNum[stick] = min<int> (topNum[stick], i);
        comb = comb>>2;
    }
    return topNum;
}

int build () {
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    dist[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int here = q.front(); q.pop();
        vector<int> topNum = getTopNumber(here);
        for (int from=0; from<4; from++) {
            // nothing in this stick
            if (topNum[from] > 12)
                continue;
            for (int to=0; to<4; to++) {
                if (from != to && topNum[from] < topNum[to]) {
                    int there = move(here, topNum[from], from, to);
                    if (dist[there] == -1) {
                        dist[there] = dist[here]+1;
                        q.push(there);
                    }
                }
            }
        }
    }
    return -1;
}

void solve() {
    int n;
    cin >> n;
    int comb = 0;
    for (int stick=3; stick>=0; stick--) {
        int m, a;
        cin >> m;
        for (int i=0; i<m; i++) {
            cin >> a;
            a = 2*(a-1);
            comb |= (stick << a);
        }
    }
    cout << dist[comb] << endl;
}

int main() {
    build();
    cin >> C;
    while (C--) {
        solve();
    }
}
