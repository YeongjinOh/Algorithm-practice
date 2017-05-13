class Solution {
public:
	// My answer
    int majorityElement(vector<int>& nums) {
        map<int, int> cnt;
        for (int i=0; i<nums.size(); i++) cnt[nums[i]]++;
        for (int i=0; i<nums.size(); i++) if (cnt[nums[i]] > nums.size()/2) return nums[i];
        return -1;
    }
	// better solution (Moore's vote algorithm)
	// Time : O(n)
	// extra space : O(1)
    int majorityElement(vector<int>& nums) {
        int maj = nums[0], cnt = 1;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] == maj) cnt++;
            else cnt--;
            if (cnt == 0) {
                maj = nums[i];
                cnt++;
            }
        }
        return maj;
    }
};
