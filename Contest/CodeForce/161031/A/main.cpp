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

bool checkVower (char c) {
    return c == 'A' || c == 'I' || c == 'E' || c == 'O' || c == 'U' || c == 'Y';
}
int max (int a, int b) {return a>b?a:b;}
int main() {
    int res = 0, cur = 0;
    char str[101];
    scanf("%s", str);
    int i=0;
    while(true) {
        cur++;
        if (checkVower(str[i]) || str[i] == '\0') {
            res = max(res, cur);
            cur = 0;
        }
        if (str[i] == '\0')
            break;
        i++;
    }
    printf("%d\n", res);

    return 0;
}
