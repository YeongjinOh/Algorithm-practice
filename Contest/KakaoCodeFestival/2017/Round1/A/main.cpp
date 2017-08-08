#include <vector>
#include <iostream>

using namespace std;

struct DisjointSet {
    vector<int> parent, size;
    DisjointSet (int n) : parent(n), size(n,1) {
        for (int i=0; i<n; i++)
            parent[i]=i; // 자기 자신으로 초기화
    }
    int find (int here) {
        if (parent[here] == here)
            return here;
        return find(parent[here]);
    }
    void merge(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return;
        size[pb] += size[pa];
        parent[pa] = pb;
    }
};
int get(int n, int i, int j) {
    return n*i+j;
}

vector<int> solution(int m, int n, vector<vector<int> > picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<int> answer(2);
    DisjointSet ds(n*m);
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (i > 0 && picture[i-1][j] == picture[i][j]) {
                ds.merge(get(n,i-1,j), get(n,i,j));
            }
            if (j > 0 && picture[i][j-1] == picture[i][j]) {
                ds.merge(get(n,i,j-1), get(n,i,j));
            }
        }
    }
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            int idx = get(n,i,j);
            if (ds.find(idx) == idx && picture[i][j] > 0) {
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, ds.size[idx]);
            }
        }
    }
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main () {
    int m, n;
    cin >> m >> n;
    vector<vector<int> > pic(m, vector<int> (n));
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            cin >> pic[i][j];
    vector<int> sol = solution(m, n, pic);
    cout << sol[0] << " " << sol[1] << endl;

    return 0;
}
