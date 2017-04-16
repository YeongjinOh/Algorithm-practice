///////////////////////////////////////////////////////////////////
//
// 문제에서 요구하는 것은 어떤 값을 검색했을 때 찾을 수 있는지 임.
// 예를 들어, 1이 여러 노드인데, 하나라도 제대로 된 위치에 있으면
// 나머지 노드는 결과에 영향을 안 줌.
//
// 하지만 나는, 각각의 노드에 대해 잘못된 위치인지를 검사했음.
//
///////////////////////////////////////////////////////////////////
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
    int cnt = 0;
    q.push(make_pair(root, make_pair(-INF,INF)));
    while(!q.empty()) {
        int cur = q.front().first;
        pii range = q.front().second;
        q.pop();
        if (v[cur] <= range.first || range.second <= v[cur]) cnt++;
        if (l[cur] >= 0)
            q.push(make_pair(l[cur],make_pair(range.first, min<int>(range.second, v[cur]))));
        if (r[cur] >= 0)
            q.push(make_pair(r[cur],make_pair(max<int>(range.first, v[cur]), range.second)));
    }
    cout << cnt << endl;
    return 0;
}
