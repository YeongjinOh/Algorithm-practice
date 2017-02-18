#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
            int n = nums.size();
            if (n==1)
                return 0;
            if (nums[0] > nums[1])
                return 0;
            if (nums[n-2] < nums[n-1])
                return n-1;
            // now n should be larger than 2
            int l = 0, r = n-1;
            while (true) {
                int mid = (l+r)/2;
                if (nums[mid-1] < nums[mid]) {
                    if (nums[mid] > nums[mid+1])
                        return mid;
                    else
                        l = mid;
                } else {
                    r = mid;
                }
            }
        }
};



int main()
{
    int n, num;
    cin >> n;
    vector<int> nums;
    for (int i=0; i<n; i++) {
        cin >> num;
        nums.push_back(num);
    }
    Solution s;
    cout << s.findPeakElement(nums) << endl;
}
