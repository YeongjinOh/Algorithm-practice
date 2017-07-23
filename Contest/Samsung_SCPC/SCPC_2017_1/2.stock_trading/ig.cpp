#include <iostream>
#include <vector>
using namespace std;
int main() {
    int tc = 1000;
    cout << tc << endl;
    for (int i=0; i<tc; i++) {
        int n = rand() % 200000+1;
        cout << n << endl;
        for (int i=0; i<n; i++)
            printf("%d ", rand());
    }
}
