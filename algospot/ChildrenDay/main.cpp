#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int strToInt (string p) {
    int res = p[0]-'0';
    for (int i=1; i<p.size(); i++) {
        res *= 10;
        res += p[i]-'0';
    }
    return res;
}

void solve() {
    string d;
    int n, m;
    cin >> d >> n >> m;
    vector<int> digit;
    for (int i=0; i<d.size(); i++)
        digit.push_back(d[i]-'0');
    sort(digit.begin(), digit.end());

    // build path
    queue<int> q;
    map<int, string> path;
    q.push(0);
    path[0] = "";
    // 2*i와 2*i+1은 각각 i인 node로 왔을 때의 path가 충분히 길지 않은 경우와 긴 경우로 나타냄
    while(!q.empty()) {
        int here = q.front(); q.pop();
        for (int i=0; i<digit.size(); i++) {
            int d = digit[i];
            int there = (10*(here/2)+d)%n;
            string p = path[here] + to_string(d);
            if (p.size() > 4 || strToInt(p) > n)
                there = 2*there+1;
            else
                there = 2*there;
            if (there == 2*m+1) {
                cout << p << endl;
                return;
            }
            if (path.count(there) == 0) {
                path[there] = p;
                q.push(there);
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return;
}


int main() {
    int C;
    cin >> C;
    while (C--) {
        solve();
    }
}
