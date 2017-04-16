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
int v[LEN], l[LEN], r[LEN], vsort[LEN];
//////////////////////////////////////////////////////////
// IMPORTANT
// vsort 상에서 [lb,rb) 만큼 현재 검색 범위에 있다.
// 아직 검색 중인데, node == -1 이면, 얘네 개수를 모두 cnt++
// 현재 상황에서 left-child, right-child로 검색 범위를 전가하기 위하여
// 지금 [lb,rb) 중에서만 가른다. (lower_bound, upper_bound를 이용하여)
///////////////////////////////////////////////////////////
int solve (int node, int lb, int rb) {
    if (rb-lb <= 0) return 0;
    if (node == -1) return rb-lb;
    int lbd = lower_bound(vsort+lb, vsort+rb, v[node])-vsort;
    int ubd = upper_bound(vsort+lb, vsort+rb, v[node])-vsort;
    return solve(l[node], lb, lbd) + solve(r[node], ubd, rb);
}

int main() {
    int n;
    scanf("%d", &n);
    memset(rt,true,sizeof(rt));
    for (int i=0; i<n; i++) {
        scanf("%d%d%d", &v[i], &l[i], &r[i]);
        if (l[i] >= 0) rt[--l[i]] = false;
        if (r[i] >= 0) rt[--r[i]] = false;
        vsort[i] = v[i];
    }
    sort(vsort, vsort+n);
    int root = 0;
    for (int i=0; i<n; i++)
        if (rt[i]) root = i;
    cout << solve(root, 0, n) << endl;
    return 0;
}
