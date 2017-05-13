class Solution {
	public:
		void backtrack (vector<bool>& visit, int cur, int size, int& cnt) {
			if (cur > size)	{
				cnt++;
				return;
			}
			for (int i=1; i<=size; i++) {
				if ((cur%i == 0 || i % cur == 0) && !visit[i]) {
					visit[i] = true;
					backtrack(visit, cur+1, size, cnt);
					visit[i] = false;
				}
			}
		}
		int countArrangement(int N) {
			vector<bool> visit(N+1, false);
			int cnt = 0;
			backtrack(visit, 1, N, cnt);
			return cnt;
		}

};
