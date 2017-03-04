#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

#define INF 987654321
#define LEN 50

using namespace std;
int C, n, m;
map<string,long long> nameIdx;
// friends[i] contians list of dishes which i-th friend can eat
// dishes[i] contians list of friends who can eat i-th dish
vector<int> friends[LEN], dishes[LEN];
int best;

// eat indicates index of friends which don't need dish any more
// for example) eat = 11 = 1011(2) indicates that only second friend need dish
void search (long long eat, int num) {

	///////////////////////////////////////////////////////////////
	// important!!!
	// eat is longer than 32 bits!!, do not use (1 << n)
	///////////////////////////////////////////////////////////////

	long long one = 1;
    if (num > best) return;
    if (eat == (one << n)-1) {
        best = min<int>(best,num);
        return;
    }

    // find friend id
    int idx;
    for (idx=0; idx<n; ++idx) {
        if ((eat & (one<<idx)) == 0) break;
    }
    if (idx == n) return;

    for (int i=0; i<friends[idx].size(); ++i) {
        int dishIdx = friends[idx][i];
        long long nextEat = eat;
        for (int j=0; j<dishes[dishIdx].size(); ++j) {
            int fIdx = dishes[dishIdx][j];
            nextEat |= (one<<fIdx);
        }
        search(nextEat, num+1);
    }
}

int main() {
    cin >> C;
    while (C--) {
        // reset
        nameIdx.clear();

        // get input
        cin >> n >> m;
        string name;
        for (int i=0; i<n; ++i) {
            cin >> name;
            nameIdx[name] = i;
        }
        for (int j=0; j<m; ++j) {
            int numberOfNames;
            cin >> numberOfNames;
            while (numberOfNames--) {
                cin >> name;
                friends[nameIdx[name]].push_back(j);
                dishes[j].push_back(nameIdx[name]);
            }
        }

        // if dish A includes entire dish B, remove dish B
        /*
         */
        best = m;
        search(0,0);
        cout << best << endl;

        // clear for next test
        for (int i=0; i<LEN; ++i) {
            friends[i].clear();
            dishes[i].clear();
        }
    }
}
