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

int abs(int a) {
    return a>0?a:-a;
}

int main() {
    int n, a;
    scanf("%d", &n);
    vector<int> odd, even;
    for (int i=0; i<n; i++) {
        scanf("%d", &a);
        if (abs(a)%2 == 1) odd.push_back(a);
        else even.push_back(a);
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    long long sum = odd.back();
    for (int i=odd.size()-2; i>=1; i-=2) {
        if (odd[i-1] + odd[i] > 0)
            sum += odd[i-1]+odd[i];
    }
    for (int i=even.size()-1; i>=0 && even[i] > 0; i--) {
        sum += even[i];
    }
    cout << sum << endl;
    return 0;
}
