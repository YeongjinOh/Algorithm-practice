#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
class Solution {
    public:
        // Time: O(kn)
        // Space: O(k)
        int maxProfit(int k, vector<int>& prices) {
            int n = prices.size();
            if (k==0 || n == 0) return 0;
            if (k > n/2) {
                int sum = 0;
                for (int i=1; i<n; i++)
                    if (prices[i-1] < prices[i])
                        sum += prices[i]-prices[i-1];
                return sum;
            }
            vector<int> buy(k, numeric_limits<int>::min()), sell(k,0);
            for (int p : prices) {
                for (int i=0; i<k; i++) {
                    if (i == 0)
                        buy[i] = max(buy[i], -p);
                    else
                        buy[i] = max(buy[i], sell[i-1]-p);
                    sell[i] = max(sell[i], buy[i]+p);
                }
            }
            return sell[k-1];
        }

        // Time: O(n + klogn)
        // Space: O(k)
        int maxProfit2(int k, vector<int>& prices) {
            priority_queue<int> profits;
            stack<pair<int, int> > st; // (v,p)
            int n = prices.size();
            int v = 0, p = -1;
            while (p < n-1) {
                v = p+1;
                while (v+1 < n && prices[v] >= prices[v+1]) { v++; }
                p = v+1;
                while (p+1 < n && prices[p] <= prices[p+1]) { p++; }

                while (!st.empty() && prices[st.top().first] > prices[v]) {
                    profits.push(prices[st.top().second] - prices[st.top().first]);
                    st.pop();
                }
                while(!st.empty() && prices[st.top().second] <= prices[p]) {
                    profits.push(prices[st.top().second] - prices[v]);
                    v = st.top().first;
                    st.pop();
                }
                st.push(make_pair(v,p));
            }
            while (!st.empty()) {
                pair<int,int> t = st.top(); st.pop();
                profits.push(prices[t.second] - prices[t.first]);
            }
            int sum = 0;
            for (int i=0; i<k && !profits.empty(); i++) {
                sum += profits.top();
                profits.pop();
            }
            return sum;
        }
};

int main() {
    int n = 1000, k = 30;
    vector<int> prices;
    for (int i=0; i<n; i++)
        prices.push_back(rand()%100000);
    Solution s;
    cout << s.maxProfit(k,prices) << endl;
    cout << s.maxProfit2(k,prices) << endl;
}
