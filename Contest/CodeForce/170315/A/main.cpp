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
ll n, k, l, r, a, b;

#define MAX 1000000

int main() {
    scanf("%lld", &n);
    int res = 0;
    char input[100];
    rep (i, 0, n) {
        scanf("%s", input);
        if (strcmp("Tetrahedron",input) == 0)
            res += 4;
        else if (strcmp("Cube", input) == 0)
            res += 6;
        else if (strcmp("Octahedron", input) == 0)
            res += 8;
        else if (strcmp("Dodecahedron", input) == 0)
            res += 12;
        else if (strcmp("Icosahedron", input) == 0)
            res += 20;
    }
    printf("%d\n",res );

    return 0;
}
