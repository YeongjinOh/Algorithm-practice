#include <iostream>
using namespace std;
#define MAX_LEN 100

int tri[MAX_LEN][MAX_LEN];
int C, n;
int max(int a, int b) { return a>b?a:b; }

int path(int i, int j) {
    if (j > i || i == n)
        return 0;
    return tri[i][j] + max(path(i+1,j),path(i+1,j+1));
}

int main() {
    cin >> C;
    while (C--) {
        cin >> n;
        for (int i=0; i<n; ++i)
            for (int j=0; j<=i; ++j)
                cin >> tri[i][j];
        cout << path(0,0) << endl;
    }
    return 0;
}
