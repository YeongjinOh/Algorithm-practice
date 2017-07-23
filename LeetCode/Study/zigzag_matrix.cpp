#include <iostream>
#include <vector>
using namespace std;

// Q1. 다음과 같은 순서로 1 to n^2이 정렬된 n by n matrix를 만들라. (단, n은 짝수)
//  0 1 5   ...
//  2 4 ...
//  3 ...
//      ... n^2-1

vector<vector<int> > zz;
vector<int> iPos, jPos;

vector<vector<int> > getZigzagMatrix(int n) {
    vector<vector<int> > res(n, vector<int> (n, 0));
    int i=0, j=0;
    bool ru = true;
    for (int k=0; k<n*n; k++) {
        res[i][j] = k;
        if (ru) {
            if (j == n-1) {
                i++;
                ru = false;
            } else if (i == 0) {
                j++;
                ru = false;
           } else {
                i--;
                j++;
            }
        } else {
            if (i == n-1) {
                j++;
                ru = true;
            } else if (j == 0) {
                i++;
                ru = true;
           } else {
                i++;
                j--;
            }
        }
    }
    return res;
}

void showMatrix(vector<vector<int> > &m) {
    for (int i=0; i<m.size(); i++) {
        for (int j=0; j<m[i].size(); j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
   cout << endl;
}

void buildKthPosition(int n) {
     for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            iPos[zz[i][j]] = i;
            jPos[zz[i][j]] = j;
        }
    }
}

pair<int, int> getKthPosition (int n, int k) {
  return make_pair(iPos[k], jPos[k]);
}

void showPosition (pair<int,int> pos) {
    printf("(%d,%d)\n", pos.first, pos.second);
}

vector<vector<int> > getRandomMatrix(int n) {
    vector<vector<int> > rm(n, vector<int> (n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            rm[i][j] = rand()%100000;
        }
    }
    return rm;
}

void insertionSort (vector<vector<int> > &rm) {
    int n = rm.size();
    for (int i=0; i<n*n; i++) {
        for (int j=i; j>0 && rm[iPos[j]][jPos[j]] < rm[iPos[j-1]][jPos[j-1]]; j--) {
            swap(rm[iPos[j]][jPos[j]], rm[iPos[j-1]][jPos[j-1]]);
        }
    }
}

// sort in [l,r)
void mergeHelper (int l, int r, vector<int> &a) {
    if (l == r) return;
    int mid = (l+r)/2;
    mergeHelper(l, mid);
    mergeHelper(mid, r);
    int i=l, j=mid;
    for (int k=0; k<r-l; k++) {
        if (i == mid) {
        }
    }
}

void mergeSort (vector<int> &a) {
    merggeHelper(0, a.size(), a);
}


int main() {
    int n;
    cin >> n;
    zz = getZigzagMatrix(n);
    iPos = vector<int> (n*n);
    jPos = vector<int> (n*n);
    buildKthPosition(n);
    vector<vector<int> > rm = getRandomMatrix(n);
    showMatrix(zz);
    showMatrix(rm);
    insertionSort(rm);
    showMatrix(rm);
    return 0;
}
