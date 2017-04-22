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

///////////////////////////////////////////////////////////
// 먼저 bipartite matching을 수행하고,
// 각 edge를 순회하면
// 1. 모두 선택됨 ->
//  1-1. 매칭된 쌍 -> 무시
//  1-2. 아닌 쌍 -> res++;
// 2. 하나만 선택 됨 ->
//  선택되지 않은 애를 이어준다.
// 3. 둘다 선택 안됨 -> 불가능한 경우
///////////////////////////////////////////////////////////
ll t, n, a, b, c;
int Agroup[1005], Bgroup[1005];
bool visit[1005];
bool dfs (vector<vector<int> >& g, int here) {
    if (visit[here]) return false;
    visit[here] = true;
    for (int i=0; i<g[here].size(); i++) {
        int there = g[here][i];
        if (Bgroup[there] == -1 || dfs(g, Bgroup[there])) {
            Agroup[here] = there;
            Bgroup[there] = here;
            return true;
        }
    }
    return false;
}
void solve () {
    cin >> n;
    string str1, str2;
    map<string, int> mp1, mp2;
    int id1=0, id2=0, cnt1=0, cnt2=0;
    vector<vector<int> > g(1005);
    for (int i=0; i<n; i++) {
        cin >> str1 >> str2;
        if (mp1[str1] == 0) mp1[str1] = ++cnt1;
        id1 = mp1[str1];
        if (mp2[str2] == 0) mp2[str2] = ++cnt2;
        id2 = mp2[str2];
        g[id1].push_back(id2);
    }
    memset(Agroup, -1, sizeof(Agroup));
    memset(Bgroup, -1, sizeof(Bgroup));
    for (int i=1; i<=cnt1; i++) {
        memset(visit, false, sizeof(visit));
        dfs(g, i);
    }
    int res = 0;
    for (int here=1; here<=cnt1; here++) {
        for (int j=0; j<g[here].size(); j++) {
            int there = g[here][j];
            if (Agroup[here] > 0 && Bgroup[there] > 0) {
                if (Agroup[here] != there && Bgroup[there] != here) res++;
            } else if (Agroup[here] > 0) {
                Bgroup[there] = here;
            } else {
                Agroup[here] = there;
            }
        }
    }
    cout << res;
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
