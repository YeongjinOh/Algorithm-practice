class Solution {
    public:

        // use pointer to ngn
        vector<int> nextGreaterElements(vector<int>& nums) {
            int n = nums.size();
            vector<int> ngn(n, -1); //
            // set ngn[n-1];
            for (int i=0; i<n-1; i++) {
                if (nums[n-1] < nums[i]) {
                    ngn[n-1] = i;
                    break;
                }
            }
            for (int i=n-2; i>=0; i--) {
                int ngIdx = i+1;
                while (ngIdx != i) {
                    if (nums[i] < nums[ngIdx]) {
                        ngn[i] = ngIdx;
                        break;
                    } else if (i>ngIdx) {
                        ngIdx = (ngIdx+1)%n;
                    } else if (nums[i] == nums[ngIdx]) {
                        ngn[i] = ngn[ngIdx];
                        break;
                    } else {
                        ngIdx = ngn[ngIdx];
                    }
                }
            }
            for (int i=0; i<n; i++) {
                if (ngn[i] >= 0)
                    ngn[i] = nums[ngn[i]];
            }
            return ngn;
        }

        // use stack
        vector<int> nextGreaterElements2(vector<int>& nums) {
            int n = nums.size();
            vector<int> ngn(n);
            if (n==0) return ngn;
            stack<int> st;
            st.push(nums[n-1]);
            for (int i=2*n-2; i>=0; i--) {
                while (!st.empty() && st.top() <= nums[i%n]) {
                    st.pop();
                }
                if (st.empty()) {
                    ngn[i%n] = -1;
                } else {
                    ngn[i%n] = st.top();
                }
                st.push(nums[i%n]);
            }
            return ngn;
        }
};
