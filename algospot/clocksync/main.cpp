#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define INF 987654321

// set relations between switches and clocks
int rel[43][2] = {
    {0,0}, {0,1}, {0,2},
    {1,3}, {1,7}, {1,9}, {1,11},
    {2,4}, {2,10}, {2,14}, {2,15},
    {3,0}, {3,4}, {3,5}, {3,6}, {3,7},
    {4,6}, {4,7}, {4,8}, {4,10}, {4,12},
    {5,0}, {5,2}, {5,14}, {5,15},
    {6,3}, {6,14}, {6,15},
    {7,4}, {7,5}, {7,7}, {7,14}, {7,15},
    {8,1}, {8,2}, {8,3}, {8,4}, {8,5},
    {9,3}, {9,4}, {9,5}, {9,9}, {9,13}
};
int clocks[16];
vector<int> switchs[10];

int min(int a, int b) { return a>b?b:a; }
// switch를 0부터 9까지 각각 3번씩 눌러보는 완전탐색
int getMin(int swt) {
    if (swt == 10) {
        for (int i=0; i<15; ++i) {
            //    printf("swt:%d clk:%d i:%d\n",swt,clocks[i],i);
            if (clocks[i] != 0)
                return INF;
        }
        return 0;
    }

    int ret = INF;
    for (int i=0; i<4; i++) {
        ret = min(ret, i+getMin(swt+1));
        for (int j=0; j<switchs[swt].size(); j++) {
            int clk = switchs[swt][j];
            clocks[clk] = (clocks[clk]+1)%4;
        }
    }
    return ret;
}
int main() {
    // sc[i] indicates the number of switch connected to i-th clock
    for (int i=0; i<43; i++) {
        switchs[rel[i][0]].push_back(rel[i][1]);
    }

    int C;
    cin >> C;
    while (C--) {
        for (int i=0; i<16; i++) {
            cin >> clocks[i];
            clocks[i] /= 3;
            clocks[i] %= 4;
        }
        int res = getMin(0);
        if (res == INF) res = -1;
        cout << res << endl;
    }


    return 0;
}
