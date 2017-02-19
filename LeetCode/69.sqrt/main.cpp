#include <iostream>
using namespace std;

// YYYYYYYNNNNNNN
// Find the last Y
// l = mid
// r = mid+1
// mid should be rounded (not downing)
class Solution {
    public:
        int mySqrt(int x) {
            int l=0, r=x;
            int mid = (l+r)/2;
            if (x < 2)
                return x;
            while (l!=r) {
                // if (mid*mid <= x) {
                if (mid <= x/mid) {
                    l = mid;
                    mid = l + (r-l+1)/2;
                } else {
                    r = mid-1;
                    mid = l + (r-l+1)/2;
                }
            }
            return l;
        }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    cout << s.mySqrt(n) << endl;
    return 0;
}
