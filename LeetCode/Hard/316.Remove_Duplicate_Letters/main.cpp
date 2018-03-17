class Solution {
    public:
        string removeDuplicateLetters(string s) {
            vector<int> cnt(26,0);
            vector<bool> used(26,false);
            for (int i=0; i<s.size(); i++)
                cnt[s[i]-'a']++;
            string res;
            for (int i=0; i<s.size(); i++) {
                while(!used[s[i]-'a'] && !res.empty() && res.back() >= s[i] && cnt[res.back()-'a'] > 0) {
                    used[res.back()-'a'] = false;
                    res.pop_back();
                }
                if (!used[s[i]-'a'])
                    res.push_back(s[i]);
                used[s[i]-'a'] = true;
                cnt[s[i]-'a']--;
            }
            return res;
        }
};
