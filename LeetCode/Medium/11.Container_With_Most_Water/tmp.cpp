#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int findUB(vector<int> &ys, int y) {
            int lo = 0, hi = ys.size();
            while (lo < hi) {
                int mid = (lo+hi)/2;
                if (ys[mid] >= y)
                    hi = mid;
                else
                    lo = mid+1;
            }
            return lo;
        }

        int findLB(vector<int> &ys, int y) {
            int lo = 0, hi = ys.size();
            while (lo < hi) {
                int mid = (lo+hi)/2;
                if (ys[mid] <= y)
                    hi = mid;
                else
                    lo = mid+1;
            }
            return lo;
        }

        int divCeil (int a, int b) {
            int res = a/b;
            if (a%b != 0) res++;
            return res;
        }
        int maxArea(vector<int> &nums) {

            int n = nums.size();
            if (n<=1) return 0;
            vector<int> xs, ys, idxs;
            xs.push_back(0);
            ys.push_back(nums[0]);
            idxs.push_back(0);
            int res = 0;
            for (int i=1; i<n; i++) {
                int m = ys.size();
                int x = i, y = nums[i];
                int lb = findUB(ys, y);
                printf("y:%d m:%d lb:%d res:%d", y, m, lb,res);
                if (lb < m) {
                    res = max(res, (x-xs[lb]) * y);
                    printf("x:%d xs[lb]:%d y:%d s:%d\n", x, xs[lb], y, (x-xs[lb])*y);

                }
                int j = findLB(idxs, x); //
//                if (j < lb)
                    res = max(res, (x-xs[j]) * ys[j]);
                printf("  j:%d res:%d\n", j,res);
                for (int i=0; i<ys.size(); i++) printf("%d ", idxs[i]);
                printf("\n");
                printf("i:%d b:%d y:%d\n", i, ys.back(), y);
                if (ys.back() < y) {
                    int a1 = xs.back(), b1 = ys.back();
                    xs.push_back(x);
                    printf("size:%d ", ys.size());
                    ys.push_back(y);
                    printf("->%d\n", ys.size());
                    idxs.push_back(divCeil(x*y-a1*b1, y-b1));
                    printf("b:%d y:%d\n", ys.back(), y);
                }
            }

            return res;
        }

};

int main() {
    Solution sol;
    int arr[] = {2,4,3,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> nums;
    for (int i=0; i<n; i++) nums.push_back(arr[i]);
    printf("\nsol:%d\n",sol.maxArea(nums));
}
