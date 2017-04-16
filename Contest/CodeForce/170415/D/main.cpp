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
#define pb push
#define fi first
#define se second
#define INF 1234567890
#define LEN 100005
bool rt[LEN];
int v[LEN], l[LEN], r[LEN];
int main() {
    int n;
    scanf("%d", &n);
    memset(rt,true,sizeof(rt));
    for (int i=0; i<n; i++) {
        scanf("%d%d%d", &v[i], &l[i], &r[i]);
        if (l[i] >= 0) rt[--l[i]] = false;
        if (r[i] >= 0) rt[--r[i]] = false;
    }
    int root = 0;
    for (int i=0; i<n; i++)
        if (rt[i]) root = i;
    queue<pair<int,pii> > q;
    map<int,int> fails; // cnt how many fails. if succeed, -1
    fails[v[root]] = -1;
    int cnt = 0;
    q.push(make_pair(root, make_pair(-INF,INF)));
    while(!q.empty()) {
        int cur = q.front().first;
        pii range = q.front().second;
        q.pop();
        if ((v[cur] <= range.first || range.second <= v[cur]) && fails[v[cur]] != -1) {
            cnt++;
            fails[v[cur]]++;
        }
        // 한번이라도 성공하면, 그동안 같은 값에서 실패해서 cnt++ 된 것들을 되돌려줘야함
        if (v[cur] > range.first && v[cur] < range.second) {
            if (fails[v[cur]] > 0) cnt -= fails[v[cur]];
            fails[v[cur]] = -1;
        }
        if (l[cur] >= 0)
            q.push(make_pair(l[cur],make_pair(range.first, min<int>(range.second, v[cur]))));
        if (r[cur] >= 0)
            q.push(make_pair(r[cur],make_pair(max<int>(range.first, v[cur]), range.second)));
    }
    cout << cnt << endl;
    return 0;
}
