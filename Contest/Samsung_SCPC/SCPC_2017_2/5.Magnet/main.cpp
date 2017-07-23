#include <vector>
#include <iostream>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
ll min (ll a, ll b) { return a>b?b:a; }
bool isIntersect(pii &stick, pii &magnet) {
    return !(stick.second < magnet.first || magnet.second < stick.first);
}

bool checkConnect(vector<bool> &used, vector<pii> mag) {
    vector<pii> magnet, stick;
    for (int i=0; i<used.size(); i++) {
        if (used[i]) magnet.push_back(mag[i]);
        else stick.push_back(mag[i]);
    }
    for (int i=0; i<stick.size(); i++) {
        bool connected = false;
        for (int j=0; j<magnet.size(); j++) {
            if (isIntersect(stick[i], magnet[j])) {
                connected = true;
            }
        }
        if (!connected) return false;
    }
    return true;
}

long long inf = 1e12;
int main(int argc, char** argv)
{
    int T, test_case;
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        int n;
        cin >> n;
        vector<pair<pii,int> > mag;
        for (int i=0; i<n; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            mag.pb(mp(mp(a,b), c));
        }
        sort(mag.begin(), mag.end());
        vector<long long> o(n, inf), xo(n, inf), xx(n, inf); // oo, xo, xx
        o[n-1] = mag[n-1].se;
        xx[n-1] = 0;
        for (int i=n-2; i>=0; i--) {
            int r = mag[i].fi.se, w = mag[i].se;
            for (int j=i+1; j<n; ++j) {
                if (r < mag[j].fi.fi) break;
                o[i] = min(o[i], o[j]+w);
                o[i] = min(o[i], xo[j]+w);
                o[i] = min(o[i], xx[j]+w);
                xo[i] = min(xo[i], o[j]);
                xx[i] = min(xx[i], xo[j]);
            }
        }
        cout << "Case #" << test_case+1 << endl;
        cout << min(o[0], xo[0]) << endl;
    }

    return 0;//Your program should return 0 on normal termination.
}
