#include <cstdio>
#include <set>
using namespace std;

int n;
long long d[100001];
set <int> cut;
set <int> :: iterator iter;
multiset <long long> res;

int main() {
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        scanf("%lld",&d[i]);
        d[i] += d[i-1];
    }
    cut.insert(0);
    cut.insert(n+1);
    res.insert(d[n]);

    int cur, l, r;
    for (int i=0; i<n; i++) {
        scanf("%d",&cur);
        iter = cut.lower_bound(cur);
        r = *iter;
        l = *(--iter);
        cut.insert(cur);
        res.erase(res.find(d[r-1]-d[l]));
        res.insert(d[r-1]-d[cur]);
        res.insert(d[cur-1]-d[l]);
        printf("%lld\n",*(--res.end()));
    }

}
