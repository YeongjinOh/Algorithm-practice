#include <iostream>
#include <time.h>

using namespace std;
typedef long long ll;




int main() {
    srand(time(NULL));
    int t = 500;
    cout << t << endl;
    while (t--) {
        int n=rand()%1000+1, m=rand()%1000+1;
        cout << n << " " << m << endl;
        for (int i=0; i<n; i++) {
            int num = rand()%1000000+1;
            printf("%d ", num);
        }
        cout << endl;
        for (int i=0; i<m; i++) {
            int b = rand()%1000000+1;
            int l = rand()%n+1, r = rand()%n+1;
            if (l > r) swap(l,r);
            printf("%d %d %d\n", b, l, r);
        }
    }
    return 0;
}
