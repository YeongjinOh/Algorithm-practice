class Solution {
    public:
        ////////////////////////////////////////////////////
        // First solution uses DFS
        ///////////////////////////////////////////////////
        void fill(int num, vector<int> &res, int n) {
            if (num > n) return;
            res.push_back(num);
            for (int i=0; i<10; i++) {
                fill(num*10+i, res, n);
            }

        }
        vector<int> getLexiOrder (int n) {
            vector<int> res;
            for (int i=1; i<10; i++) {
                fill(i, res, n);
            }
            return res;
        }

        ////////////////////////////////////////////////////
        // Second solution use simple iteration
        // Much faster
        ////////////////////////////////////////////////////
        vector<int> lexicalOrder(int n) {
            vector<int> res(n);
            int cur = 1;
            for (int i=0; i<n; i++) {
                res[i] = cur;
                if (cur*10 <= n) {
                    cur *= 10;
                } else {
                    if (cur >= n) {
                        cur/=10;
                    }
                    cur++;
                    while (cur%10 == 0) {
                        cur /= 10;
                    }
                }
            }
            return res;
        }
};
