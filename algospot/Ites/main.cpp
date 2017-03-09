#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

#define a 214013
#define b 2531011
#define MOD 10000

using namespace std;
int C;

int main() {
    cin >> C;
    while (C--) {
        int  k, n;
        cin >> k >> n;
        unsigned int s = 1983;
        queue<int> q;
        q.push(s);
        int sum = s;
        int cnt = 0;
        int left, right;
        for (int i=0; i<n; i++) {
            s = a*s+b;
            int num = s % MOD + 1;
            q.push(num);
            sum += num;
            while(sum > k) {
                sum -= q.front();
                q.pop();
            }
            if (sum == k) cnt++;
        }
        cout << cnt << endl;
    }
}
