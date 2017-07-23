#include <iostream>
#include <time.h>

using namespace std;
typedef long long ll;

// ax + by = gcd(a,b)
ll gcdExtended(ll a, ll b, ll &x, ll &y) {
    if (b > a) return gcdExtended(b,a,y,x);
    if (a%b == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x0, y0;
    ll g = gcdExtended(b, a%b, x0, y0);
    x = y0;
    y = x0 - (a/b) * y0;
    return g;
}


int main() {
    srand(time(NULL));
    int t = 30;
    cout << t << endl;
    while (t--) {
        int n=rand()%4+2;
        cout << n << endl;
        for (int i=0; i<n; i++) {
            //int s = rand()%99+2, l = rand()%999+10, d = rand()%l;
            ll s = rand()%39+2, l = rand()%99+10, d = rand()%l;
            ll x, y, g;
            g = gcdExtended(s, l, x, y);
            while (d%g != 0) {
                d = rand()%l;
            }
            printf("%d %d %d\n", s, l, d);
        }
    }
    return 0;
}
