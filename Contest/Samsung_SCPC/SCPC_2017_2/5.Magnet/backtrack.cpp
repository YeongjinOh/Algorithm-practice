#include <vector>
#include <iostream>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;

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

void backtrack(int idx, vector<bool> &used, vector<pii> &mag, vector<int> &w, int curW, int &minW) {
    if (idx == mag.size()) {
        if (curW > minW) return;
        if (checkConnect(used, mag)) {
            minW = curW;
        }
        return;
    }
    used[idx] = true;
    backtrack(idx+1, used, mag, w, curW+w[idx], minW);
    used[idx] = false;
    backtrack(idx+1, used, mag, w, curW, minW);
}

int main(int argc, char** argv)
{
    int T, test_case;
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        int n;
        cin >> n;
        vector<pii> mag;
        vector<int> w;
        for (int i=0; i<n; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            mag.pb(mp(a,b));
            w.pb(c);
        }
        int ans = 9999999;
        vector<bool> used(n, false);
        backtrack(0, used, mag, w, 0, ans);
        cout << "Case #" << test_case+1 << endl;
        cout << ans << endl;
    }

    return 0;//Your program should return 0 on normal termination.
}
