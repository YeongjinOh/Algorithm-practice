#include <iostream>
#include <cstring>
#include <istream>
#include <sstream>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <vector>
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
#define double long double // use long double when using bisection
#define LEN 2005

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1. a[i]와 b[i]를 이용하여 num[i], num[j] 간의 모든 inequality를 구한다.
//  1-1. for i<j, num[i] > num[j] if a[i] >= a[j]
//  1-2. for i<j, num[i] < num[j] if b[i] <= b[j]
/
//  **** IMPORTANT ****
//  1-3. LIS에서, 예를 들어, a[i]=m이라고 할 때, a[j]=m-1인 largest j에 대하여 (j<i)  num[j]<num[i]는 보장된다.
// 2. inequality에 맞게 solution을 빌드한다.
//  2-1. 각 i에 대해, i보다 큰 수의 개수를 센다.
//  2-2. 가장 큰 수(cnt=0 인 수)부터 하나씩 채워 나간다.
//  2-3. 방금 채워진 수가 영향을 주었던 (ineq에서) 수들의 cnt를 줄인다.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int t, n;
int a[LEN], b[LEN], lastIdx[LEN];
bool ineq[LEN][LEN];
void solve () {
    cin >> n;
    rep(i,0,n) rep(j,0,n) ineq[i][j] = false;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    for (int i=0; i<n; i++) {
        lastIdx[a[i]] = i;
        for (int j=0; j<i; j++)
            if (a[j] >= a[i]) ineq[j][i] = true;
        if (a[i] > 1) // i-th number is greater than (last index of a[i]-1)-th number
            ineq[i][lastIdx[a[i]-1]] = true;
    }
    for (int i=n-1; i>=0; i--) {
        lastIdx[b[i]] = i;
        for (int j=i+1; j<n; j++)
            if (b[i] <= b[j]) ineq[j][i] = true;
        if (b[i] > 1) // i-th number is greater than (last index of a[i]-1)-th number
            ineq[i][lastIdx[b[i]-1]] = true;
    }
    vector<int> cnt(n, 0), res(n);
    vector<bool> visit(n, false);
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (ineq[i][j]) cnt[j]++;
    for (int num=n; num>0; num--) {
        int idx = n-1;
        while (idx >= 0 && (cnt[idx] > 0 || visit[idx])) { idx--; }
        res[idx] = num;
        visit[idx] = true;
        for (int j=0; j<n; j++)
            if (ineq[idx][j])
                cnt[j]--;
    }
    for (int i=0; i<n; i++) printf("%d ", res[i]);
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
        fprintf(stderr, "case %d done\n", i);
    }
    return 0;
}
