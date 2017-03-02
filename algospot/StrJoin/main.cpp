#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#define LEN 100

using namespace std;
int C, n, len;
//multiset<int> s;
priority_queue<int, vector<int>, greater<int> > pq;

int main() {
    cin >> C;
    while (C--) {
//        s.clear();
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> len;
            // s.insert(len);
            pq.push(len);
        }
        int sum = 0, cur;
        multiset<int>::iterator it;
        while (pq.size() > 1) {
            cur = pq.top(); pq.pop();
            cur += pq.top(); pq.pop();
            sum += cur;
            pq.push(cur);
        }
        cout << sum << endl;
        pq.pop();
    }
}
