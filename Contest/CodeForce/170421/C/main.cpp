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
long long a[100005];
int n;
#define MAX 100000

long long gcd (long long a, long long b) {
    if (a < b) return gcd(b, a);
    if (b < 0) return gcd(a, -b);
    if (b == 0) return a;
    if (a%b == 0) return b;
    return gcd(b, a%b);
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    int g = a[0];
    for (int i=1; i<n; i++) {
        g = gcd(a[i], g);
    }
    int cnt = 0;
    if (g < 2) {
        for (int i=1; i<n; i++) {
            while (gcd(a[i-1],2) != 2) {
                long long sub = a[i-1] - a[i], sum = a[i-1] + a[i];
                a[i-1] = sub;
                a[i] = sum;
                cnt++;
            }
        }
        while (gcd(a[n-1],2) != 2) {
            long long sub = a[n-2] - a[n-1], sum = a[n-2] + a[n-1];
            a[n-2] = sub;
            a[n-1] = sum;
            cnt++;
        }
    }
    cout << "YES" << endl;
    cout << cnt << endl;

    return 0;
}
