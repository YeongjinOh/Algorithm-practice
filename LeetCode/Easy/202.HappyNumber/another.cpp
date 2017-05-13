#include <iostream>
#include <cstring>

using namespace std;


class Solution {
    public:
        int getHappy(int n) {
            int happy = 0;
            while(n>0) {
                happy += (n%10)*(n%10);
                n /= 10;
            }
            return happy;
        }
        bool isHappy(int n) {
            int slow = n, fast = n;
            do {
                slow = getHappy(slow);
                fast = getHappy(getHappy(fast));
            } while (slow != fast);
            return slow == 1;
        }
};
int main() {
    Solution s;
    int num;
    cin >> num;
    cout << s.isHappy(num) << endl;
    return 0;
}
