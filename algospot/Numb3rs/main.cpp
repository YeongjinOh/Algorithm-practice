#include <iostream>

#define MAX_TOWNS 50
using namespace std;
int C,N,D,P,T;
// probability from town i to town j
double p[MAX_TOWNS][MAX_TOWNS];
// current D-th day's probability of each i-th town
double curp[2][MAX_TOWNS];
int main() {
    cin >> C;
    while (C--) {
        cin >> N >> D >> P;
        for (int i=0; i<N; ++i) {
            double rowsum = 0;
            for (int j=0; j<N; ++j) {
                cin >> p[i][j];
                rowsum += p[i][j];
            }
            for (int j=0; j<N; ++j) {
                p[i][j] /= rowsum;
            }
        }
        for (int i=0; i<N; ++i)
            curp[0][i] = 0;
        curp[0][P] = 1;
        for (int d=1; d<=D; ++d) {
            // for each day
            // current : d%2 th row
            // previous : (d-1)%2 th row

            // reset
            for (int j=0; j<N; ++j) {
                curp[d%2][j] = 0;
            }
            for (int i=0; i<N; ++i) {
                for (int j=0; j<N; ++j) {
                    curp[d%2][j] += p[i][j]*curp[(d+1)%2][i];
                }
            }
        }

        int Q,n;
        cin >> Q;
        while (Q--) {
            cin >> n;
            printf("%.8lf ",curp[D%2][n]);
        }
        cout << endl;
    }
}
