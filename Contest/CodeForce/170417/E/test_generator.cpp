#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;


int main() {
    int n, m = 200000;
    vector<bool> check(m, false);

    for (int i=0; i<500; i++) {
        check[rand()%m] = true;
    }
    vector<int> ban;
    for (int i=0; i<m-1; i++) {
        ban.push_back(i);
    }
    cout << ban.size() << " " << m << endl;
    for (int i=0; i<ban.size(); i++)
        printf("%d ", ban[i]);
}
