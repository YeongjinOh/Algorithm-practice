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


int p[1001];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    memset(p,0,sizeof(p));
    map<int, int> mp;
    vector<int> vt;
    int d=2;
    int sum = 0;
    while(n > 1) {
        if (n%d == 0) {
            if (mp[d] == 0)
                vt.push_back(d);
            mp[d]++;
            sum++;
            n /= d;
        } else
            d++;
    }
    if (k > sum) {
        cout << -1 << endl;
        return 0;
    }
    while (k > 1) {
        k--;
        int num = vt.back();
        cout << num << " ";
        if (--mp[num] == 0) vt.pop_back();
    }
    int p = 1;
    for (int i=0; i<vt.size(); i++) {
        for (int j=0; j<mp[vt[i]]; j++)
            p *= vt[i];
    }
    cout << p << endl;

    return 0;
}
