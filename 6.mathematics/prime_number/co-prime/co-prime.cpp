#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int> divider;
long long a, b;
long long res;

// count number of integers divided by p between a and b
long long count (int p) { return (long long)(b/p) - (long long)((a-1)/p);}

// get recursively
void get (int cur, int cnt, int mult) {
    if (cur == divider.size()) {
        if (cnt%2 == 1) res -= count(mult);
        else  res += count(mult);
        return;
    }
    get(cur+1, cnt+1, mult*divider[cur]);
    get(cur+1, cnt, mult);
}

int main () {
    int t;
    scanf("%d",&t);
    for(int test_case=1; test_case<=t; test_case++) {
        long long n;
        scanf("%lld%lld%lld",&a,&b,&n);
        divider.clear();
        long long cur=n;
        // push all prime divider of n
        for (int i=2; i*i<=n; i++)
            if(cur % i == 0) {
                divider.push_back(i);
                while(cur%i == 0) { cur = cur/i;}
                if (cur==1) break;
            }
        if (cur != 1) divider.push_back(cur);
        res = 0;
        get(0,0,1);
        printf("Case #%d: %lld\n", test_case, res);
    }
    return 0;
}
