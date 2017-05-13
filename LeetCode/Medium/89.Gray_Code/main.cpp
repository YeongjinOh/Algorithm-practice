class Solution {
	public:

		void fillGray (int base, vector<int>& res) {
			if (base == 1) {
				int last = res.back();
				last ^= 1;
				res.push_back(last);
				return;
			}
			fillGray(base>>1,res);
			int last = res.back();
			res.push_back(last^base);
			fillGray(base>>1,res);
		}
		vector<int> grayCode(int num) {
			vector<int> res;
			res.push_back(0);
			if (num == 0) return res;
			fillGray(1<<(num-1), res);
			return res;
		}
};
