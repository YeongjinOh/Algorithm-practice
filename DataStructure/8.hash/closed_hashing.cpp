#include <iostream>
#include <vector>
using namespace std;

// Linear Probing
struct Hash {
    vector<pair<int, int> > table;
    int m;
    Hash(int n) : table(n), m(n) { }
    int hashFunc(int key) {
        return (key*17)%m;
    }
    int probe (int key, int i) {
        return 19*i;
    }
    void insert (int b, int c) {
        int home = hashFunc(b);
        pair<int, int> p(b,c);
        int pos = home;
        for (int i=1; table[pos].first != 0; i++) {
            pos = (home + probe(b,i)) % m;
            if (i == m) {
                printf("full\n");
                return;
            }
        }
        table[pos] = p;
    }
    int find (int b) {
        int home = hashFunc(b);
        int pos = home, i = 1;
        while (table[pos].first != 0 && table[pos].first != b) {
            pos = (home + probe(b,i++)) % m;
            if (i == m) return -1;
        }
        return table[pos].second;
    }
    void print() {
        printf("Hash : ");
        for (int i=0; i<m; i++) printf("(%d,%d) ", table[i].first,table[i].second);
        printf("\n");
    }

};

int main() {

    Hash hs(7);
    while (true) {
        int a, b, c;
        cin >> a;
        if (a==1) {
            cin >> b >> c;
            hs.insert(b,c);
        } else if (a==0) {
            hs.print();
        } else {
            cin >> b;
            cout << hs.find(b) << endl;
        }
    }
    return 0;
}
