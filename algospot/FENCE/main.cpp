#include <iostream>

using namespace std;
int fence[20005];
int n;
int max (int a, int b) { return a>b?a:b;}
int getMax (int s, int e)
{
    if (s >= e)
        return 0;
    if (s+1 == e)
        return fence[s];
    int minval=987654321, minidx=0;
    for (int i=s; i<e; i++)
    {
        if (fence[i] < minval)
        {
            minval = fence[i];
            minidx = i;
        }
    }
    return max(minval*(e-s), max(getMax(s,minidx),getMax(minidx+1,e)));
}
int main()
{
    int C;
    cin >> C;
    while(C--)
    {
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> fence[i];
        cout << getMax(0,n) << endl;
    }
    return 0;
}
