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
ll n, k, l, r;
ll a[1000], b[1000];
int offset = 0;

typedef pair<int,char> line;
vector<line> res;

// a[start] 부터 a[end] 까지 sum이 맞는건 보장 됨. 만들면서 막히는게 없는지만
bool checkRange (int start, int end) {

}

int main() {
    scanf("%lld", &n);
    for (int i=1; i<=n; i++)
        scanf("%lld", &a[i]);
     scanf("%lld", &k);
    for (int i=1; i<=n; i++)
        scanf("%lld", &b[i]);




    return 0;
}
