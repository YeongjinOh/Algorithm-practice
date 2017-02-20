#include <iostream>
#include <cstring>
#include <vector>
#define MAX_LEN 500

using namespace std;
int C,n;
vector<int> c;

int main() {
    cin >> C;
    while (C--) {
        cin >> n;
        int tmp;

        // first element
        cin >> tmp;
        c.clear();
        c.push_back(tmp);

        for (int i=1; i<n; ++i) {
            cin >> tmp;

            // if largest value so far
            if (c[c.size()-1] < tmp)
                c.push_back(tmp);
            else {
                // else, find my largest length position
                // ex) tmp = 5;
                // c = [1, 2, 4, 5(6), 7, 10];
                //      N  N  N    Y   Y  Y
                // NNNNNNNNYYYYYYY  -> ( ]
                // by binary search
                int l=0, r=c.size()-1, mid=(l+r)/2;
                while (l!=r) {
                    if (c[mid] < tmp)
                        l = mid+1;
                    else
                        r = mid;
                    mid = (l+r)/2;
                }
                // replace
                c[l] = tmp;
            }
        }
        cout << c.size() << endl;
    }
}
