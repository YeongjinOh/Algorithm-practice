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
typedef pair<ll,ll> pll;
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


ll n, k;

void read() {
    cin >> n >> k;
}


void solve () {
    priority_queue<ll> q;
    map<ll,ll> mp;
    mp[n]++;
    q.push(n);
    ll sm, lg;
    while(k > 0) {
        ll t = q.top(); q.pop();
        sm = (t-1)/2, lg = (t-1)-sm;
        if (mp[lg] == 0)
            q.push(lg);
        mp[lg] += mp[t];
        if (mp[sm] == 0)
            q.push(sm);
        mp[sm] += mp[t];
        k -= mp[t];
    }
    cout << lg << " " <<  sm;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        read();
        solve();
        cout << endl;
    }
    return 0;
}
