class Solution {
    public:
        int findMin(vector<int>& nums) {
            int l = 0, r = nums.size()-1;
            if (nums[l] <= nums[r]) return nums[l];
            // keep nums[l] > nums[r]
            while (l<r && nums[l] < nums[l+1]) {
                int mid = (l+r)/2;
                if (nums[l] > nums[mid]) r = mid;
                else l = mid;
            }
            return nums[l+1];
        }
};

