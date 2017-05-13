class NumArray {
	vector<int> nums;
	public:
	NumArray(vector<int> num) : nums(num) {
		for (int i=1; i<nums.size(); i++)
			nums[i] += nums[i-1];
	}

	int sumRange(int i, int j) {
		if (i>j) return sumRange(j,i);
		if (i==0) return nums[j];
		return nums[j] - nums[i-1];
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
