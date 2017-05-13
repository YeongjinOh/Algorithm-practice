#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:

        int findMaximumMatchInBipartite (vector<int>& a, vector<int>& b, int base) {
            if (a.size() < b.size()) return findMaximumMatchInBipartite(b,a,base);
            if (b.size() == 0) return 0;
            if (b.size() == 1 || base == 0) {
                int maxXor = 0;
                for (int i=0; i<a.size(); i++) maxXor = max(maxXor, b[0]^a[i]);
                return maxXor;
            }
            vector<int> a1, a0, b1, b0;
            for (int i=0; i<a.size(); i++) {
                if ((a[i] & base) == 0) a0.push_back(a[i]);
                else a1.push_back(a[i]);
            }
            for (int i=0; i<b.size(); i++) {
                if ((b[i] & base) == 0) b0.push_back(b[i]);
                else b1.push_back(b[i]);
            }
            // if every numbers in a and b has same bit at base
            if ((a1.size() == 0 || b0.size() == 0) && (a0.size() == 0 || b1.size() == 0))
                return findMaximumMatchInBipartite(a,b,base>>1);
            return max(findMaximumMatchInBipartite(a1,b0,base>>1), findMaximumMatchInBipartite(a0,b1,base>>1));
        }

        int getLargestDiffBit (vector<int>& nums) {
            int n = nums.size();
            if (n <= 1) return 0;
            int base = 1 << 30;
            for (int base = (1<<30); base>=1; base>>=1)
                for (int i=1; i<n; i++)
                    if ((base & (nums[0] ^ nums[i])) != 0) return base;
            return 0;
        }

        int findMaximumXOR(vector<int>& nums) {
            int base = getLargestDiffBit(nums);
            if (base == 0) return 0;
            vector<int> a, b;
            for (int i=0; i<nums.size(); i++) {
                if ((nums[i]&base) == 0) a.push_back(nums[i]);
                else b.push_back(nums[i]);
            }
            return findMaximumMatchInBipartite(a,b,base>>1);
        }

};

int main() {
    vector<int> nums;
    int n; cin >> n;
    while (n--) {
        int a; cin >> a;
        nums.push_back(a);
    }
    Solution sol;
    cout << sol.findMaximumXOR(nums) << endl;
}
