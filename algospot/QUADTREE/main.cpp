#include <iostream>
#include <cstring>
using namespace std;
string str;

// return next unit start index
int get(int s)
{
    if (str[s] != 'x') {
        return s+1;
    }
    int s2 = get(s+1);
    int s3 = get(s2);
    int s4 = get(s3);
    return get(s4);
}
void print(int s, int e) {
    cout << str[s];
    if (s==e) {
        return;
    }
    int s1 = s+1;
    int s2 = get(s1);
    int s3 = get(s2);
    int s4 = get(s3);
    print(s3,s4-1);
    print(s4,e);
    print(s1,s2-1);
    print(s2,s3-1);
}

int main()
{
    int C;
    cin >> C;
    while (C--)
    {
        cin >> str;
        //xabcd -> xcdab
        print(0,str.size()-1);
        cout << endl;
    }

    return 0;
}
