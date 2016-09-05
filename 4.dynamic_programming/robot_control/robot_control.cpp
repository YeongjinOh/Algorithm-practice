#include <cstdio>
#include <iostream>
 
using namespace std;
 
// input value array
int val[1000][1000];
 
// dynamic array optimal value from dleft, dright
int dleft[1000][1000];
int dright[1000][1000];
 
int max(int a, int b){return a>b?a:b;}
 
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            scanf("%d",&val[i][j]);
 
    // build the first row
    dleft[0][0] = val[0][0];
    dright[0][0] = val[0][0];
    for (int i=1; i<m; i++) {
        dleft[0][i] = dleft[0][i-1] + val[0][i];
        dright[0][i] = dleft[0][i];
    }
 
    // from the second row
 
    for (int i=1; i<n; i++) {
        // copy max value among dleft and dright
        for (int j=0; j<m; j++) {
            dleft[i][j] = max(dleft[i-1][j], dright[i-1][j]) + val[i][j];
            dright[i][j] = dleft[i][j];
        }
 
        // compare the value from top with the value from left or right
        for (int j=1; j<m; j++) {
            dleft[i][j] = max(dleft[i][j], dleft[i][j-1]+val[i][j]);
            dright[i][m-1-j] = max(dright[i][m-1-j], dright[i][m-j]+val[i][m-1-j]);
        }
    }
    printf("%d\n", max(dleft[n-1][m-1], dright[n-1][m-1]));
 
    return 0;
}