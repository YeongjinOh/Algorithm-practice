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
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define fi first
#define se second
int n, m, k, l, r, a, b;
map<int, int> mp;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    vector<bool> hole(n+1, false);
    for (int i=0; i<m; i++) {
        scanf("%d", &a);
        hole[a] = true;
    }
    int cup = 1;
    bool still = true;
    if (hole[cup])
        still = false;
    for (int i=0; i<k; i++) {
        scanf("%d%d", &a, &b);
        if (still) {
            if (cup == a)
                cup = b;
            else if (cup == b)
                cup = a;
            if (hole[cup])
                still = false;
        }
    }
    printf("%d\n", cup);

    return 0;
}
