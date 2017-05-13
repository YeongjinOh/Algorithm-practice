class Solution {
    public:

        bool checkInclusion(string s1, string s2) {
            int n = s1.size(), m = s2.size();
            if (n > m) return false;
            vector<int> cnt(26,0), zero(26,0);
            for (int i=0; i<n; i++) cnt[s1[i]-'a']++;
            for (int j=0; j<n; j++) cnt[s2[j]-'a']--;
            if (cnt == zero) return true;
            for (int j=n; j<m; j++) {
                cnt[s2[j-n]-'a']++;
                cnt[s2[j]-'a']--;
                if (cnt == zero)
                    return true;
            }
            return false;
        }
};
