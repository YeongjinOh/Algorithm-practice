class Solution {
    public:
        int findNthDigit(int n) {
            if (n<=0) return 0;
            int k=0, groupCnt = 0, prevGroupCnt = -1, pow = 1;

            while (prevGroupCnt < groupCnt && groupCnt < n) {
                n -= groupCnt;
                k++;
                prevGroupCnt = groupCnt;
                groupCnt = k*9*pow;
                pow *= 10;
            }
            // now  0 <= n < groupCnt, k is length of digits in this group

            int idxDigitInGroup = n; // 1~
            int idxNumberInGroup = (idxDigitInGroup-1) / k + 1 ; // 1~
            int idxDigitInNumber = (idxDigitInGroup-1)%k+1;// 1,2, …, k
            int startNumberInGroup = pow/10;
            int theNumber = startNumberInGroup + idxNumberInGroup - 1;
            // remove right digits
            for (int i=0; i<k-idxDigitInNumber; i++)
                theNumber/=10;
            return theNumber%10;

        }
};
