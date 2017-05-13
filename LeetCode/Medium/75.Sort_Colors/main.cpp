class Solution {
	public:
		void sortColors(vector<int>& array) {
			int l = 0, r = array.size()-1, m = l;
			while (l <= m && m <= r) {
				if (array[m] == 0) {
					swap(array[m], array[l]);
					l++;
					//			    if (l > m) m = l;
					m++;
				} else if (array[m] == 2) {
					swap(array[m], array[r]);
					r--;
				} else {
					m++;
				}
			}
		}

		// another way
		// [0, i) gauranteed to be sorted at each time
		void sortColors(vector<int>& nums) {
			int b = 0, c = 0;
			for (int i=0; i<nums.size(); i++) {
				if (nums[i] == 0) {
					swap(nums[i], nums[b++]);
					swap(nums[i], nums[c++]);
				} else if (nums[i] == 1) {
					swap(nums[i], nums[c++]);
				}
			}
		}
};

