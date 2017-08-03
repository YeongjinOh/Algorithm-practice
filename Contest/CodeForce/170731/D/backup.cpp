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
#define LEN 5005
string str;
bool p[LEN][LEN];
int kp[LEN][LEN];

void get(vector<int> &res, int l, int r) {
    int len = r-l+1;
    if (len <= 2) return;
    int t = len/2;
    if (len % 2 == 1) {
        res.pb(l+t);
    }
    get(res, l, l+t-1);
}

int main() {
    cin >> str;
    int n = str.size();
    memset(p, 0, sizeof(p));
    memset(kp, 0, sizeof(kp));
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; ++i) {
        p[i][i] = true;
        kp[i][i] = 1;
        cnt[0]++;
    }
    for (int i = 0; i < n-1; ++i)
        if (str[i] == str[i+1]) {
            p[i][i+1] = true;
            kp[i][i+1] = 1;
            cnt[0]++;
        }

    for (int len=3; len<=n; len++) {
        for (int i=0; i+len-1<n; i++) {
            int j = i+len-1;
            if (p[i+1][j-1] && str[i] == str[j]) {
                p[i][j] = true;
                kp[i][j] = 1;
                cnt[0]++;
            }
        }
    }

    for (int k=2, minlen=2; k<=n && minlen <= n; k++, minlen*=2) {
        for (int len=1; len<=n; ++len) {
            for (int i=0; i+len-1<n; ++i) {
                int j = i+len-1;
                int t = len/2;
                if (kp[i][i+t-1] >= k-1 && kp[j-t+1][j] >= k-1 && p[i][j]) {
/*                    vector<int> res;
                    get(res, i, i+t-1);
                    int gap = t + len%2;
                    bool eq = (str[i] == str[i+gap]);
                    for (int s=0; s<res.size() && eq; s++) {
                        eq = (str[res[s]] == str[res[s]+gap]);
                    }
                    if (eq) {
*/                        kp[i][j] = k;
                        cnt[k-1]++;
 //                   }
                }
            }
        }
    }
    for (int i=0; i<n; i++)
        printf("%d ", cnt[i]);
    cout<<endl;
    return 0;
}
