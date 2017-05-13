class Solution {
	public:
		int findMaxLength(vector<int>& nums) {
			int cnt[2] = {0,0};
			unordered_map<int,int> hash;
			int res = 0;
			hash[0] = -1;
			for (int i=0; i<nums.size(); i++) {
				cnt[nums[i]]++;
				int diff = cnt[0] - cnt[1];
				if (hash.find(diff) == hash.end())
					hash[diff] = i;
				else
					res = max(res, i-hash[diff]);
			}
			return res;
		}
};
