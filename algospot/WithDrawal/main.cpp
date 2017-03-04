#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define LEN 1000
using namespace std;
int C, n, k;

struct subject {
    int c;
    int r;
    double rc;
    bool operator < (const subject cmp) const {
        return rc > cmp.rc;
    };
};
subject subjects[LEN];

// check the rank is smaller than or equal to value
bool check(double value) {
    for (int i=0; i<n; ++i)
        subjects[i].rc = subjects[i].c * value - subjects[i].r;
    sort(subjects, subjects+n);
    double sum = 0;
    for (int i=0; i<k; ++i)
        sum += subjects[i].rc;
    return sum >= 0;
}
int main() {
    cin >> C;
    while (C--) {
        cin >> n >> k;
        for (int i=0; i<n; i++)
            cin >> subjects[i].r >> subjects[i].c;
        int sumC = 0, sumR = 0;
        for (int i=0; i<k; ++i) {
            sumC += subjects[i].c;
            sumR += subjects[i].r;
        }
        double l = 0.0, r = 1.0;
        while(r-l > 0.00000001) {
            double mid = (l+r)/2;
            if (check(mid)) r = mid;
            else l = mid;
        }
        printf("%.10lf\n",r);
    }
}
