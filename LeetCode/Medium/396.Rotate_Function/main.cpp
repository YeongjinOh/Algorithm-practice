class Solution {
    public:
        ///////////////////////////////////////////////////
        // Time : O(n)
        // Extra space : O(1)
        ///////////////////////////////////////////////////
        int maxRotateFunction(vector<int>& nums) {
            int sum = 0, F = 0, n = nums.size();
            for (int i=0; i<n; i++) {
                sum += nums[i];
                F += i*nums[i]; // F0
            }
            int res = F;
            for (int i=n-1; i>0; i--) {
                F += sum - n * nums[i];
                res = max(res, F);
            }
            return res;
        }
};
