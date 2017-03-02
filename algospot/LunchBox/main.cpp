#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define LEN 10000
using namespace std;
int C, n;
struct lunch {
    int m;
    int e;
    bool operator<(const lunch& cmp) const {
        return e > cmp.e;
    }
};
lunch box[LEN];

int main() {
    cin >> C;
    while (C--) {
        cin >> n;
        for (int i=0; i<n; ++i) cin >> box[i].m;
        for (int i=0; i<n; ++i) cin >> box[i].e;
        sort (box, box+n);
        int res = 0, jump = 0;
        for (int i=0; i<n; ++i) {
            res = max(res, jump + box[i].m + box[i].e);
            jump += box[i].m;
        }
        cout << res << endl;
    }
}
