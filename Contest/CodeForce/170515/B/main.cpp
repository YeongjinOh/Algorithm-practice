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
#define LEN 200005

int n, k;
int a[LEN];
long long sum[LEN];

int main() {
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    sum[0] = 0;
    for (int i=1; i<=n; i++)
        sum[i] = sum[i-1]+a[i-1];
    long long totalSum = 0;
    for (int i=0; i+n-k+1 <= n; i++) {
        totalSum += sum[i+n-k+1]-sum[i];
    }
    printf("%.10lf\n", (double)totalSum/(double)(n-k+1));
    return 0;
}
