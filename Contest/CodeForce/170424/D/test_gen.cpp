#include <iostream>
using namespace std;

int main() {
    int n = 80, k = 80, m = 2000, c = 1;
    cout << n << " " << k << endl << m << endl;
    int cnt = m*m;
    for (int i=1; i<=n && cnt; i++) {
        for (int j=i+1; j<=n && cnt; j++) {
            printf("%d %d %d\n", i, j, c);
            printf("%d %d %d\n", j, i, c);
            cnt--;
        }
    }
}
