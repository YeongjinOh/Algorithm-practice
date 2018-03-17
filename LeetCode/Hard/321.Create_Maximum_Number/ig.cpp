#include <iostream>
using namespace std;

int main() {
    int n = 500;
    printf("%d\n", n);
    for (int i=0; i<n; i++) printf("%d ", rand()%10);
    cout << endl;
    for (int i=0; i<n; i++) printf("%d ", rand()%10);
    cout << endl;
}
