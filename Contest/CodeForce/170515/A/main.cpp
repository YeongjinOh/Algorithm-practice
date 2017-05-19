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

int n;

int main() {
    scanf("%d", &n);
    int cnt = 0, m = n;
    while (m>=10) {
        m/=10;
        cnt++;
    }
    m++;
    for (int i=0; i<cnt; i++) m*=10;
    printf("%d", m-n);
    return 0;
}
