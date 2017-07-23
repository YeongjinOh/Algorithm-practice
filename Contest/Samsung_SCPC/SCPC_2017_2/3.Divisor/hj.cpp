#include <cstdio>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <iostream>
using namespace std;
#define LEN 1000005

vector<int> prime;
void buildPrime() {
    vector<bool> p(LEN, true);
    for (int i=2; i*i<=LEN; i++) {
        if (p[i]) {
            prime.push_back(i);
            for (int j=i*i; j<=LEN; j+=i)
                p[j] = false;
        }
    }
}

bool check(vector<pair<int,int> > &vpii, int l, int r) {
    int n = vpii.size();
    if (vpii[n-1].second < l) return true;
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo+hi)/2;
        if (vpii[mid].second < l) lo=mid+1;
        else hi = mid;
    }
    return vpii[lo].first > r;
}


void dfs(vector<pair<int,int> > &pii, vector<int>& dv, int i, int f) {
    if (i == pii.size()) {
        dv.push_back(f);
        return;
    }
    for (int j=0, ff=1; j<=pii[i].second; j++, ff*=pii[i].first) {
        dfs(pii, dv, i+1, f*ff);
    }
}


vector<int> dvs(int a) {
    vector<pair<int, int> > pii;
    for (int i=0; i<prime.size() && a > 1; ++i) {
        int k = 0;
        while (a%prime[i] == 0) {
            k++;
            a/=prime[i];
        }
        if (k > 0) {
            pii.push_back(make_pair(prime[i],k));
        }
    }
    if (a > 1) {
        pii.push_back(make_pair(a,1));
    }
    vector<int> res;
    dfs(pii, res, 0, 1);
    return res;
}

int main() {
    buildPrime();
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int n, m;
        scanf("%d%d", &n, &m);
        unordered_map<int, vector<pair<int,int> > > mp;
        long long res = 0;
        for (int i=1; i<=n; ++i) {
            int a;
            cin >> a;
            vector<int> dv = dvs(a);
            for (int j=1; j<dv.size(); ++j) {
                vector<pair<int,int> > &vpii = mp[dv[j]];
                if (!vpii.empty() && vpii.back().second == i-1) {
                    vpii.back().second = i;
                } else {
                    vpii.push_back(make_pair(i,i));
                }
            }
        }
        for (int i=0; i<m; ++i) {
            int b, l, r;
            scanf("%d%d%d", &b, &l, &r);
            vector<int> dv = dvs(b);
            for (int j=1; j<dv.size(); ++j) {
                vector<pair<int,int> > &vpii = mp[dv[j]];
                if (vpii.empty() || check(vpii, l, r)) {
                    res++;
                }
            }
        }

        printf("Case #%d\n", tc);
        printf("%lld\n", res);
    }
}

