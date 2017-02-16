#include <iostream>
#include <vector>

using namespace std;
int fence[20005];
int n;
int max (int a, int b) { return a>b?a:b;}
int main()
{
    int C;
    cin >> C;
    while(C--)
    {
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> fence[i];
        vector<int> stack;
        int maxArea = 0, curArea, cur, last;
        stack.push_back(-1);
        for (int i=0; i<n; i++)
        {
            while(stack.size() > 1 && fence[stack.back()] >= fence[i]) {
                cur = stack.back();
                stack.pop_back();
                last = stack.back();
                curArea = (i-last-1)*fence[cur];
                maxArea = max(maxArea,curArea);
            }
            stack.push_back(i);
        }
        while (stack.size() > 1)
        {
            cur = stack.back();
            stack.pop_back();
            last = stack.back();
            curArea = (n-last-1)*fence[cur];
            maxArea = max(maxArea,curArea);
        }
        cout << maxArea << endl;
    }
    return 0;
}
