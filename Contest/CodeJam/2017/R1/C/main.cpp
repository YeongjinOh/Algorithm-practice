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
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 5e18


ll t, n, a, b, c;


void solve () {
    int Hd, Ad, Hk, Ak, B, D;
    cin >> Hd >> Ad >> Hk >> Ak >> B >> D;
    map<vector<int>, bool> visit;
    queue<pair<vector<int>, int> > q;
    vector<int> state;
    state.push_back(Hd);
    state.push_back(Ad);
    state.push_back(Hk);
    state.push_back(Ak);
    q.push(make_pair(state, 0));
    while(!q.empty()) {
        vector<int> t = q.front().first;
        int turn = q.front().second;
//        printf("%d %d %d %d\n", t[0], t[1], t[2], t[3]);
        q.pop();
        visit[t] = true;
        if (t[2] <= 0) {
            cout << turn;
            return;
        } else if (t[0] <= 0)
            continue;
        vector<vector<int> > nxt;
        // attack
        vector<int> attack = t;
        attack[2] -= attack[1];
        attack[0] -= attack[3];
        nxt.push_back(attack);
        // buff
        vector<int> buff = t;
        buff[1] += B;
        buff[0] -= buff[3];
        nxt.push_back(buff);
        // cure
        vector<int> cure = t;
        cure[0] = Hd;
        cure[0] -= cure[3];
        nxt.push_back(cure);
        // debuff
        vector<int> debuff = t;
        debuff[3] -= D;
        debuff[3] = max<int>(0, debuff[3]);
        debuff[0] -= debuff[3];
        nxt.push_back(debuff);
        for (int i=0; i<nxt.size(); i++) {
            vector<int> &cur = nxt[i];
            if (t[2] <= 0) {
                cout << turn+1;
                return;
            } else if (t[0] <= 0) continue;
            if (!visit[cur]) {
                visit[cur] = true;
                q.push(make_pair(cur,turn+1));
            }
        }
    }
    cout << "IMPOSSIBLE";
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
    return 0;
}
