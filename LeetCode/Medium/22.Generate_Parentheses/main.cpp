class Solution {
public:
    void add (int left, int right, int n, string str, vector<string>& res) {
        if (right > left || left > n) return;
        if (left == right && left == n) {
            res.push_back(str);
            return;
        }
        add(left+1, right, n, str+"(", res);
        add(left, right+1, n, str+")", res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        add(0,0,n,"",res);
        return res;
    }
};

