#include <set>
#include <iostream>

using namespace std;

int main() {
    int nums[] = {20, 5, 18, 35, 7};
    set <int> myset (nums, nums+5);
    multiset<int> mymultiset (myset.begin(), myset.end());
    myset.insert(21);
    myset.insert(20);
    mymultiset.insert(21);
    mymultiset.insert(20);

    cout << " - set - " << endl;
    for (set<int>::iterator iter = myset.begin(); iter != myset.end(); iter++) {
        printf("%d ",*iter);
    }
    cout << endl;
    cout << " - multiset - " << endl;
    for (multiset<int>::iterator iter = mymultiset.begin(); iter != mymultiset.end(); iter++) {
        printf("%d ",*iter);
    }
    cout << endl;
    return 0;
}
