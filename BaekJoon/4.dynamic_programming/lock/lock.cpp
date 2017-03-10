#include <cstdio>
#include <iostream>
#define INF 987654
#define MAX 100
using namespace std;
int pw[MAX+3];
int d[MAX][2];
// pre-calculated table how many steps we need to make this combination
int num[10][10][10];

int min (int a, int b) { return a>b?b:a;}
int sym(int n) { if (n==0) return 0; return 10-n; } // for symmetry 0-9
int steps(int n) { if (n==0) return 0; return (n-1)/3+1;} // how many steps to make it zero

int main() {
    int n;
    char tmp[MAX+1];
    scanf("%d",&n);
    scanf("%s",tmp); // thorw away new enter character
    for (int i=1; i<=n; i++)
        pw[i] = tmp[i-1];
    // pw would be < 0 a b c d ... e f 0 0 >
    pw[0] = 0;
    pw[n+1] = 0;
    pw[n+2] = 0;
    scanf("%s",tmp);
    for (int i=1; i<=n; i++)
        pw[i] = (pw[i] - tmp[i-1] + 10)%10;

    // initialize dynamic array
    for (int i=0; i<MAX; i++)
        for (int j=0; j<2; j++)
            d[i][j] = INF;
    d[10*pw[1]+pw[2]][0] = 0;

    // initialize the number of ways
    for (int i00=0; i00<10; i00++)
        for (int i0=0; i0<10; i0++)
            for (int i=0; i<10; i++)
                num[i00][i0][i] = INF;

     for (int i00=0; i00<10; i00++)
        for (int i0=0; i0<10; i0++)
            for (int i=0; i<10; i++)
                if (i00 >= i0 && i0 >= i) {
                    int cur = steps(i) + steps(i0-i) + steps(i00-i0);
                    num[i00][i0][i] = min(num[i00][i0][i], cur);
                    num[sym(i00)][sym(i0)][sym(i)] = min(num[sym(i00)][sym(i0)][sym(i)], cur);
                }

    for (int idx=0; idx<n; idx++) {
        // initialize
        int cur = idx%2;
        int nxt = (idx + 1)%2;
        for (int j=0; j<MAX; j++)
            d[j][nxt] = INF;

        // overwrite minimum
        int p3 = pw[3+idx];
        for (int j=0; j<MAX; j++) {
            if (d[j][cur] != INF) {
                int p1 = j/10;
                int p2 = j%10;
                for (int i0=0; i0<10; i0++) {
                    for (int i=0; i<10; i++) {
                        if (num[sym(p1)][i0][i] != INF) {
                            int tmp2 = (p2 + i0)%10;
                            int tmp3 = (p3 + i)%10;
                            int tmp_idx = tmp2*10+tmp3;
                            d[tmp_idx][nxt] = min(d[tmp_idx][nxt], d[j][cur]+num[sym(p1)][i0][i]);
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",d[0][n%2]);
}
