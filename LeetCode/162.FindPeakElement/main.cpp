#include <iostream>
#include <vector>

using namespace std;

class Solution {
    private:
        int a;
        int b;
        int c;
        void checkLeft(const vector<int>& nums) {
            int mid = (a+b)/2;
            if (nums[b] == nums[mid])
                mid++;
            if (nums[b] > nums[mid])
                a = mid;
            else {
                c = b;
                b = mid;
            }
        }
        void checkRight(const vector<int>& nums) {
            int mid = (b+c)/2;
            if (nums[b] == nums[mid])
                mid--;
            if (nums[b] > nums[mid])
                c = mid;
            else {
                a = b;
                b = mid;
            }
        }
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
            a = 0, b = 1, c = n-1;
            while(b-a!=1 || c-b !=1) {
                if (b-a < c-b)
                    checkRight(nums);
                else
                    checkLeft(nums);
            }
            return b;
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
