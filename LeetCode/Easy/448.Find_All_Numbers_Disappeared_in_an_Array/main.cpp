class Solution {
public:
    void swap (int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i=1; i<=nums.size(); i++) {
            while (nums[i-1] != i && nums[nums[i-1]-1] != nums[i-1]) {
                swap(nums[i-1], nums[nums[i-1]-1]);
            }
        }
        vector<int> res;
        for (int i=1; i<=nums.size(); i++) if (nums[i-1] != i) res.push_back(i);
        return res;
    }
	// this solution doesn't change input array nums
    vector<int> findDisappearedNumbers2(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            int m = abs(nums[i])-1;
            if (nums[m] > 0) nums[m] = -nums[m];
        }
        vector<int> res;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > 0) res.push_back(i+1);
            else nums[i] = -nums[i];
        }
        return res;
    }
};

