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
string str;
int main() {
    scanf("%d%d", &n, &k);
    cin >> str;
    vector<bool> visit(26, false);
    vector<int> s(26, -1), e(26, -1);
    for (int i=0; i<n; i++) {
        int idx = str[i]-'A';
        visit[idx] = true;
        if (s[idx] == -1)
            s[idx] = i;
        e[idx] = i;
    }
    for (int i=0; i<n; i++) {
        int cnt = 0;
        for (int j=0; j<26; j++) {
            if (visit[j] && s[j] <= i && i <= e[j])
                cnt++;
        }
        if (cnt > k) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
