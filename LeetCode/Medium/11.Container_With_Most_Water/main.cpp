class Solution {
    public:
        int maxArea(vector<int> &nums) {
            int n = nums.size();
            if (n<=1) return 0;
            int l = 0, r = n-1, res = 0;
            while (l<r) {
                res = max(res,(r-l)*min(nums[l], nums[r]));
                if (nums[l] < nums[r]) l++;
                else r--;
            }
            return res;
        }
};
