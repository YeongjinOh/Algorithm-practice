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
int n, m;

///////////////////////////////////////////////////////////////////////////
//
// 2의 배수와 4의 배수 집합은 다르게 봐줘야함.
// 2의 배수에서 4의 배수로 넘어가는 것은 가능하지만 반대는 불가.
//
///////////////////////////////////////////////////////////////////////////
int gcd (int a, int b) {
    if (b > a) return gcd(b, a);
    if (a % b == 0) return b;
    return gcd(b, a%b);
}

bool relative_prime(int n, vector<int> factor) {
    for (int i=0; i<factor.size(); i++)
        if (gcd(n,factor[i]) != 1) return false;
    return true;
}

int inverse (int before, int after) {
    for (int i=0; i<m; i++) {
        if ((before*i)%m == after)
            return i;
    }
    return 0;
}

int main() {
    scanf("%d%d", &n, &m);
    if (m == 1) {
        cout << 1 << endl << 0 << endl;
        return 0;
    }
    vector<int> visit(m,false);
    for (int i=0; i<n; i++) {
        int a;
        scanf("%d", &a);
        visit[a] = true;
    }
    vector<int> factor;
    int mm = m;
    for (int i=2; mm>1; i++) {
        if (mm%i == 0) {
            factor.push_back(i);
            while(mm%i == 0) {
                mm/=i;
            }
        }
    }
    int start = -1;
    for (int i=1; i<m; i++) {
        if (!visit[i] && relative_prime(i, factor)) {
            start = i;
            break;
        }
    }

    vector<int> sol;
    if (start != -1) {
        sol.push_back(start);
        for (int i=start+1; i<m; i++) {
            if (!visit[i] && relative_prime(i, factor)) {
                sol.push_back(inverse(start, i));
                start = i;
            }
        }
    }

    // find min factor
    int maxCnt = -1, maxFactor = -1;
    for (int i=0; i<factor.size(); i++) {
        int f = factor[i];
        int cnt = 0;
        for (int j=0; j*f<m; j++)
            if (!visit[j*f]) cnt++;
        if (cnt > maxCnt) {
            maxCnt = cnt;
            maxFactor = f;
        }
    }
    if (start == -1) {
        start = 1;
    }
    factor.erase(find(factor.begin(), factor.end(), maxFactor));
    for (int i=maxFactor; i<m; i+=maxFactor) {
        if (!visit[i] && relative_prime(i, factor)) {
            sol.push_back(inverse(start, i));
            start = i;
        }
    }
    if (!visit[0])
        sol.push_back(0);
    cout << sol.size();
    if (sol.size() > 0) cout << endl;
    for (int i=0; i<sol.size(); i++)
        printf("%d ", sol[i]);
    cout << endl;
    return 0;
}
