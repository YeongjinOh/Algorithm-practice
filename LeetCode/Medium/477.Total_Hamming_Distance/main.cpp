class Solution {
    public:
        // bitwise count
        int totalHammingDistance(vector<int>& nums) {
            int totalHammingDist = 0;
            for (int i=0, base=1; i<32; i++, base<<=1) {
                int cnt[2] = {0, 0};
                for (int j=0; j<nums.size(); j++) {
                    if ((base & nums[j]) == 0) cnt[0]++;
                    else cnt[1]++;
                }
                totalHammingDist += cnt[0]*cnt[1];
            }
            return totalHammingDist;
        }

        // similar solution but faster
        int totalHammingDistance(vector<int>& nums) {
            int totalHammingDist = 0;
            vector<int> cnt(32,0);
            int n = nums.size();
            for (int i=0; i<n; i++) {
                int num = nums[i];
                int j = 0;
                while (num>0) {
                    cnt[j++] += num&1;
                    num>>=1;
                }
            }
            for (int i=0; i<32; i++) {
                totalHammingDist += cnt[i]*(n-cnt[i]);
            }
            return totalHammingDist;
        }
};
