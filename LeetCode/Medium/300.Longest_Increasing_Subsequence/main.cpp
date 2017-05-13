class Solution {
    public:
        //////////////////////////
        // first way
        // Time: O(n^2)
        /////////////////////////
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            if (n == 0) return 0;
            vector<int> res(n,1);
            int maxVal = 1;
            for (int i=1; i<n; i++) {
                for (int j=0; j<i; j++) {
                    if (nums[i] > nums[j]) {
                        res[i] = max(res[i], res[j]+1);
                    }
                }
                maxVal = max(maxVal, res[i]);
            }
            return maxVal;
        }

        //////////////////////////
        // second way
        // Time : O(nlogn)
        /////////////////////////
        int findIdx (vector<int> &lis, int num) {
            int lo = 0, hi = lis.size()-1;
            while (lo < hi) {
                int mid = (lo+hi)/2;
                if (lis[mid] >= num) hi = mid;
                else lo = mid + 1;
            }
            return lo;
        }
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            if (n == 0) return 0;
            vector<int> lis;
            lis.push_back(nums[0]);
            for (int i=1; i<n; i++) {
                if (nums[i] > lis.back()) {
                    lis.push_back(nums[i]);
                } else {
                    int idx = findIdx(lis, nums[i]);
                    lis[idx] = nums[i];
                }
            }
            return lis.size();
        }
};
