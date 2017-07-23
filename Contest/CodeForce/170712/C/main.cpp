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

int main() {
    scanf("%d", &n);
    vector<pair<int, pair<string, vector<int> > > > vpp;
    int len = 0;
    while (n--) {
        string str;
        cin >> str;
        int k;
        cin >> k;
        vector<int> pos;
        int maxp = 0;
        while (k--) {
            int p;
            scanf("%d", &p);
            p--;
            pos.pb(p);
            if (maxp < p) maxp = p;
        }
        if (len < str.size() + maxp) len = str.size() + maxp;
        vpp.pb(mp(str.size(), mp(str, pos)));
    }
    vector<char> res(len, 'a');
    vector<bool> visit(len, false);
    sort(vpp.begin(), vpp.end());
    for (int i = vpp.size()-1; i>=0; i--) {
        string &str = vpp[i].se.fi;
        vector<int> &pos = vpp[i].se.se;
        for (int j=0; j<pos.size(); j++) {
            int start = pos[j];
            if (visit[start]) continue;
            visit[start] = true;
            for (int k=0; k<str.size();  k++) {
                res[start+k] = str[k];
            }
        }
    }
    for (int i=0; i<res.size(); i++) printf("%c", res[i]);
    cout << endl;
    return 0;
}
