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
int get(char c) {
    switch (c) {
        case '^':
            return 0;
        case '>':
            return 1;
        case 'v':
            return 2;
        case '<':
            return 3;
    }
    return -1;
}
int main() {
    char st, en;
    scanf("%c %c", &st, &en);
    scanf("%d", &n);
    int s = get(st), e = get(en);
    if (n%2 == 1) {
        if ((s+n)%4 == e) {
            cout << "cw" << endl;
        } else if(s == (e+n)%4) {
            cout << "ccw" << endl;
        } else {
            cout << "undefined" << endl;
        }
    } else {
            cout << "undefined" << endl;
    }

    return 0;
}
