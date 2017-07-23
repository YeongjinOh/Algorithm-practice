#include <iostream>
#define LEN 100000
using namespace std;

int main() {
    int T = 1;
    cout << T << endl;
    while (T--) {
        int N = 1000;
        cout << N << endl;
        for (int i=0; i<N; i++) {
            int r = rand()%LEN+1, h = rand()%LEN+1;
            printf("%d %d\n", r, h);
        }

    }

}
