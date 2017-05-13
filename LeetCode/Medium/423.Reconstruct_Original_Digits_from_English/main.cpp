class Solution {
	public:
		string originalDigits(string input) {
			string alpha[10] = {"zero","one","two", "three", "four", "five","six", "seven", "eight", "nine"};
			char rep[10] = {'z', 'o', 'w', 'h', 'u', 'f', 'x', 'v', 'g', 'i'};

			int cnt[26], nums[10];
			for (int i=0; i<26; i++) cnt[i] = 0;
			for (int i=0; i<10; i++) nums[i] = 0;
			for (int i=0; i<input.size(); i++) cnt[input[i]-'a']++;
			for (int i=0; i<10; i+=2) {
				while (cnt[rep[i]-'a']) {
					nums[i]++;
					for (int j=0; j<alpha[i].size(); j++) {
						cnt[alpha[i][j]-'a']--;
					}
				}
				if (i==8) i=-1;
			}
			string res = "";
			for (int i=0; i<10; i++)
				for (int j=0; j<nums[i]; j++)
					res += std::to_string(i);
			return res;
		}
};
