class Solution {
public:
    int climbStairs(int n) {
		// NOTE
		// we don't need array for this problem
		/*
        int sum[n+1];
        for (int i=0; i<=n; i++) sum[i] = 0;
        sum[0] = sum[1] = 1;
        for (int i=2; i<=n; i++) sum[i] = sum[i-1] + sum[i-2];
        return sum[n];
		*/
		if (n < 2) return 1;
        int a = 0, b = 1, c = a+b;
        for (int i=2; i<=n; i++) {
            a=b;
            b=c;
            c=a+b;
        }
        return c;
    }
};
