#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
int C;

vector<int> intToComb(int n) {
    vector<int> res;
    while(n>0) {
        res.push_back(n%10);
        n/=10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int combToInt (vector<int>& comb) {
    int n = comb[0];
    for (int i=1; i<comb.size(); i++) {
        n *= 10;
        n += comb[i];
    }
    return n;
}

bool isSorted (vector<int>& comb) {
    for (int i=1; i<comb.size(); i++)
        if (comb[i-1] > comb[i]) return false;
    return true;
}

int getSwaped (vector<int> comb, int begin, int end) {
    reverse(comb.begin()+begin, comb.begin()+end);
    return combToInt(comb);
}

// 최악의 경우 O(V+E) * 8(변환시간) 인데, V=8!, E=8!*28 이므로 느리다.
int bfs(vector<int> & order) {
    int start = combToInt(order);
    // (number which represents combination, distance)
    queue<pair<int,int> > q;
    q.push(make_pair(start, 0));
    map <int, bool> visit;
    while(!q.empty()) {
        pair<int, int> t = q.front(); q.pop();
        int dist = t.second;
        vector<int> here = intToComb(t.first);
        if (isSorted(here)) return dist;
        for (int i=1; i<here.size(); i++) {
            for (int j=0; j<i; j++) {
                int swaped = getSwaped(here, j, i+1);
                if (!visit[swaped]) {
                    q.push(make_pair(swaped, dist+1));
                    visit[swaped] = true;
                }
            }
        }
    }
    return -1;
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

    // get minimal distance
    int ans = bfs(order);
    cout << ans << endl;
}

int main() {
    cin >> C;
    while (C--) {
        solve();
    }
}
