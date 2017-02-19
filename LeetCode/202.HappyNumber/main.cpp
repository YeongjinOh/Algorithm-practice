#include <iostream>
#include <cstring>

using namespace std;

// not least
// upper bound of cycle numbers
static const int MAX = 300;
static int cache[MAX];

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
        bool helper(int n) {
            if (n==1)
                return true;
            int happy = getHappy(n);
            if (n > MAX)
                return helper(happy);
            if (cache[n] == 0)
                return false;
            cache[n] = 0;
                return helper(happy);
        }
        bool isHappy(int n) {
            memset(cache,-1,sizeof(cache));
            return helper(n);
        }
};
int main() {
    Solution s;
    int num;
    cin >> num;
    cout << s.isHappy(num) << endl;
    return 0;
}
