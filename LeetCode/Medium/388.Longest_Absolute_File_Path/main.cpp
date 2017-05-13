class Solution {
    public:
        int lengthLongestPath(string &path) {
            string res = "";
            int n = path.size(), l = 0, r = 0;
            vector<int> len;
            int sum = -1, maxSum = 0;
            while (r < n) {
                int cntT = 0;
                while (r<n && path[r] == '\t') { r++; cntT++; }
                l = r;
                bool isFile = false;
                while (r<n && path[r] != '\n') {
                    if (path[r] == '.') isFile = true;
                    r++;
                }
                while(len.size() > cntT) {
                    sum -= len.back(); len.pop_back();
                }
                len.push_back(r-l+1);
                sum += r-l+1;
                if (isFile)
                    maxSum = max(maxSum, sum);
                r++;
            }
            return maxSum;
        }

};

