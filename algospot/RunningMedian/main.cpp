#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MOD 20090711
using namespace std;
int C, n, a, b;
int sum, cur;

/////////////////////////////////////////////////////
// TODO : use treap instead of heap
// //////////////////////////////////////////////////
int main() {
    cin >> C;
    while (C--) {
        cin >> n >> a >> b;
        long long cur = 1983;
        sum = cur;
        int median = cur;

        // minq contains elements greater than median
        // maxq contains elements less than median
        priority_queue<int, vector<int>, greater<int> > minq;
        priority_queue<int, vector<int>, less<int> > maxq;

        for (int i=1; i<n; i++) {
            cur = (cur*a+b)%MOD;
            // unbalanced -> minq has (k+1)-elements, while maxq has k-elements
            if (i%2 == 0) {
                if (cur < median)
                    maxq.push(cur);
                else {
                    minq.push(cur);
                    maxq.push(median);
                    median = minq.top();
                    minq.pop();
                }
            } else {
                if (cur < median) {
                    maxq.push(cur);
                    minq.push(median);
                    median = maxq.top();
                    maxq.pop();
                } else {
                    minq.push(cur);
                }
            }
            sum = (sum + median) % MOD;
        }
        cout << sum << endl;
    }
}
