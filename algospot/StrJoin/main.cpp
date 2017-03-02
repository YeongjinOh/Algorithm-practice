#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#define LEN 100

using namespace std;
int C, n, len;
multiset<int> s;

int main() {
    cin >> C;
    while (C--) {
        s.clear();
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> len;
            s.insert(len);
        }
        int sum = 0, cur;
        multiset<int>::iterator it;
        while (s.size() > 1) {
            it = s.begin();
            cur = *it;
            s.erase(it);
            it = s.begin();
            cur += *it;
            s.erase(it);
            sum += cur;
            s.insert(cur);
        }
        cout << sum << endl;
    }
}
