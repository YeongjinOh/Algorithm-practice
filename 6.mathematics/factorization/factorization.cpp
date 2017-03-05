#include <iostream>
#include <algorithm>
using namespace std;
int main () {
    int n;
    cin >> n;
    int start = 2;
    for (int i = start; n>1; i++) {
        while (n%i == 0) {
            cout << i << endl;
            n /= i;
        }
    }
    return 0;
}
