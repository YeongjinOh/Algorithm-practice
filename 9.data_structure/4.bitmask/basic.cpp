#include <iostream>
using namespace std;

// bitmask represent set
int getEmptySet () {
    return 0;
}
int getFullSet (int len) {
    return (1<<len)-1;
}
void addElement (int& bm, int idx) {
    bm |= 1<<idx;
}

// remove if exists
void removeElement (int& bm, int idx) {
    // bm -= 1<<idx;
    bm &= ~(1<<idx);
}

void toggleElement (int& bm, int idx) {
    bm ^= 1<<idx;
}

int findLeastElement (int bm) {
    return bm & -bm;
}

void removeLeastElement (int& bm) {
    bm &= (bm-1)
}
