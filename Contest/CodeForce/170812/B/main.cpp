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

int n, k;
int a[105];

int main() {
    scanf("%d%d", &n, &k);
    for (int i=0; i<k; i++) scanf("%d", &a[i]);
    int numOfFour = n, numOfTwo = 2*n;
    for (int i=0; i<k; i++) {
        while (a[i] >= 4 && numOfFour > 0) {
            a[i] -= 4;
            numOfFour--;
        }
    }
    numOfTwo += numOfFour;
    int numOfOne = numOfFour;
    for (int i=0; i<k; i++) {
        while (a[i] >= 2 && numOfTwo > 0) {
            a[i] -= 2;
            numOfTwo--;
        }
    }
    for (int i=0; i<k; i++) {
        while (a[i] > 0) {
            a[i]--;
            if (numOfTwo > 0) numOfTwo--;
            else numOfOne--;
        }
    }
    if (numOfOne < 0) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}
