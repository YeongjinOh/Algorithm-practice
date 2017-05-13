class Solution {
    public:
        //////////////////////////////////////////////////////////////////////
        // Solution 1) DFS
        /////////////////////////////////////////////////////////////////////
        bool checkPal(string &s, int l, int r) {
            while (l<r) {
                if (s[l++] != s[r--]) return false;
            }
            return true;
        }
        vector<vector<string>> partition(string s) {
            if (s.size() == 0) {
                return vector<vector<string> >(1);
            }
            vector<vector<string> > res;
            for (int i=0; i<s.size(); i++) {
                if (checkPal(s,0, i)) {
                    vector<vector<string> > sub = partition(s.substr(i+1));
                    string subPal = s.substr(0,i+1);
                    for (int j=0; j<sub.size(); j++) {
                        reverse(sub[j].begin(), sub[j].end());
                        sub[j].push_back(subPal);
                        reverse(sub[j].begin(), sub[j].end());
                        res.push_back(sub[j]);
                    }
                }
            }
            return res;
        }


        ////////////////////////////////////////////////////////////////////
        // Solution 2) Back-tracking
        ////////////////////////////////////////////////////////////////////
        bool checkPal(string &s, int l, int r) {
            while (l<r) {
                if (s[l++] != s[r--]) return false;
            }
            return true;
        }
        void backtrack (vector<vector<string> > &res, vector<string> &cur, string &s, int pos) {
            if (pos == s.size()) {
                res.push_back(cur);
                return;
            }
            for (int i = pos; i<s.size(); i++) {
                if (checkPal(s,pos,i)) {
                    cur.push_back(s.substr(pos,i-pos+1));
                    backtrack(res, cur, s, i+1);
                    cur.pop_back();
                }
            }
        }
        vector<vector<string>> partition(string s) {
            int n = s.size();
            vector<vector<string> > res;
            vector<string> cur;
            backtrack(res, cur, s, 0);
            return res;
        }

};
