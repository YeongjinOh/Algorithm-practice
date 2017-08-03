#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
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

int s,v1,v2,t1,t2;

int main() {
    scanf("%d%d%d%d%d", &s, &v1, &v2, &t1, &t2);
    ll a = s*v1 + 2*t1, b = s*v2 + 2*t2;
    if (a<b) cout << "First" << endl;
    else if (a>b) cout << "Second" << endl;
    else cout << "Friendship" << endl;
    return 0;
}
