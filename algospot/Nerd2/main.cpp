#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int C, n, cnt, sum, p, q;

map<int,int> mp;

// check if there exists (p', q') in mp such that p'>p and q'>q
bool isIncluded (int p, int q) {
    map<int, int>::iterator iter = mp.lower_bound(p);
    if (iter == mp.end()) return false;
    return iter->second > q;
}
int main() {
    cin >> C;
    while (C--) {
        cin >> n;
		// reset
        cnt = 0;
        sum = 0;
		mp.clear();

        for (int i=0; i<n; i++) {
            scanf("%d%d",&p,&q);
            if (isIncluded(p,q)) {
                sum += mp.size();
                continue;
            }
            // check if (p,q) include any (p',q') in mp
            map<int, int>::iterator iter = mp.lower_bound(p);
            if (iter != mp.begin()) {
                iter--;
                while (true) {
                    if (iter->second > q) break;
                    if (iter == mp.begin()) {
                        mp.erase(iter);
                        break;
                    }
                    map<int, int>::iterator tmp = iter;
                    tmp--;
                    mp.erase(iter);
                    iter = tmp;
                }
            }


            // insert current (p,q)
            mp[p] = q;
            sum += mp.size();
        }
        cout << sum << endl;
    }
}
