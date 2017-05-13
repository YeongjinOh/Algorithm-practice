class Solution {
    public:
        int convertStrToInt(string str) {
            int res = 0;
            for (int i=0; i<str.size(); i++)
                res = 10*res + str[i]-'0';
            return res;
        }
        int calcByOperator (int a, int b, char symbol) {
            switch(symbol) {
                case '+':
                    return a+b;
                case '-':
                    return a-b;
                case '*':
                    return a*b;
            }
            return -1;
        }
        vector<int> diffWaysToCompute(string str) {
            vector<int> sym;
            for (int i=0; i<str.size(); i++) {
                if (str[i] == '+' || str[i] == '-' || str[i] == '*')
                    sym.push_back(i);
            }
            if (sym.size() == 0) return {convertStrToInt(str)};
            vector<int> res;

            for (int i=0; i<sym.size(); i++) {
                vector<int> left, right;
                left = diffWaysToCompute(str.substr(0,sym[i]));
                right = diffWaysToCompute(str.substr(sym[i]+1));
                for (int l=0; l<left.size(); l++) {
                    for (int r=0; r<right.size(); r++) {
                        res.push_back(calcByOperator(left[l], right[r], str[sym[i]]));
                    }
                }
            }
            return res;
        }
};
