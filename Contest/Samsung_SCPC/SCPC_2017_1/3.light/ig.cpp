#include <iostream>
#include <vector>
using namespace std;
int main() {
    int tc = 1;
    cout << tc << endl;
    for (int i=0; i<tc; i++) {
        int n = 100, m = 100;
        printf("%d %d\n", n, m);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                printf("0 0 0 ");
            }
            printf("\n");
        }
    }
}
