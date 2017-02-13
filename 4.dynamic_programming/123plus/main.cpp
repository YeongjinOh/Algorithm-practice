#include <cstdio>
#include <iostream>
using namespace std;

int T, n;
int sol[20];
int main() {
    sol[0] = 1;
    sol[1] = 1;
    sol[2] = 2;
    for (int i=3; i<15; i++) {
        sol[i] = sol[i-1] + sol[i-2] + sol[i-3];
    }
    cin >> T;
    while(T--) {
        cin >> n;
        cout << sol[n] << endl;
    }

    return 0;
}
