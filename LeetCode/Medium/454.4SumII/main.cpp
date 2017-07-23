class Solution {
	public:
		int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
			unordered_map<int,int> sumOfAandB;
			for (int i=0; i<A.size(); i++) {
				for (int j=0; j<B.size(); j++) {
					sumOfAandB[A[i]+B[j]]++;
				}
			}
			int cnt = 0;
			for (int i=0; i<C.size(); i++) {
				for (int j=0; j<D.size(); j++) {
					cnt += sumOfAandB[-1*(C[i]+D[j])];
				}
			}
			return cnt;
		}
};
