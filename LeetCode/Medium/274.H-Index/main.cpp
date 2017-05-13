class Solution {
    public:
        /////////////////////////////////////////////////
        // Solution 1) simple solution using sort
        // Time : O(nlogn)
        // Extra space : O(1)
        /////////////////////////////////////////////////
        int hIndex(vector<int>& citations) {
            sort(citations.begin(), citations.end());
            int n = citations.size(), i = 0;
            while (i<n) {
                if (citations[i] >= n-i) return n-i;
                i++;
            }
            return 0;
        }

        /////////////////////////////////////////////////
        // Solution 2) similar solution using bisection
        // Time : O(nlogn)
        // Extra space : O(1)
        /////////////////////////////////////////////////
        int hIndex2(vector<int>& citations) {
            int n=citations.size(), l=0, r=n;
            while (l<r) {
                int mid = (l+r)/2;
                int cntG = 0, cntL = 0;
                for (int i=0; i<n; i++) {
                    if (citations[i] > mid) cntG++;
                    else if (citations[i] < mid) cntL++;
                }
                if (cntG <= mid && cntL <= n-mid) return mid;
                if (cntG > mid) {
                    l = mid+1;
                } else {
                    r = mid;
                }
            }
            return l;
        }


        //////////////////////////////////////////////////////////
        // Solution 3) count the number of numbers greater than i
        // Time : O(n)
        // Extra space : O(n)
        //////////////////////////////////////////////////////////
        int hIndex(vector<int>& citations) {
            int n = citations.size();
            vector<int> cnt(n+1,0);
            for (int i=0; i<n; i++) cnt[citations[i] > n? n:citations[i]]++;
            for (int i=n; i>=0; i--) {
                if (i < n) cnt[i] += cnt[i+1];
                if (cnt[i] >= i) return i;
            }
            return -1;
        }
};
