class Solution {
    public:
        ///////////////////////////////////////////
        // Solution 1) Simple
        // Time : O(n)
        ///////////////////////////////////////////
        int hIndex(vector<int>& citations) {
            int n = citations.size();
            for (int i=0; i<n; i++) {
                if (citations[i] >= n-i) return n-i;
            }
            return 0;
        }

        ///////////////////////////////////////////
        // Solution 2) Bisection
        // Time : O(logn)
        ///////////////////////////////////////////
        int hIndex(vector<int>& citations) {
            int n = citations.size();
            int l = 0, r = n;
            while (l<r) {
                int mid = (l+r)/2;
                if (citations[mid] >= n-mid) r = mid;
                else l = mid+1;
            }
            return n-l;
        }
};


