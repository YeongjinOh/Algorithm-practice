// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
typedef pair<int, int> pr;
struct comp {
    bool operator() (pr a, pr b) {
        return a.second > b.second;
    }
};

const int sz = 1001;
vector<pr> a[sz];
int dist[sz];
bool visit[sz];
bool pass[sz]; // true if any shortest path pass this campus

void resetVisit(int n) {
    for (int i=1; i<=n; i++)
        visit[i] = false;
}

void dijkstra(int source, int n) {

    resetVisit(n);

    // initialize distance
    for (int i=1; i<=n; i++) {
        dist[i] = INF;
    }
    dist[source] = 0;

	priority_queue<pr,vector<pr>,comp> pq;
	pq.push(make_pair(source,0));
	while(!pq.empty()) {
		pr curr = pq.top();
		pq.pop();
		int cv = curr.first, cu = curr.second;
		if (visit[cv])
			continue;
		visit[cv] = true;
		for (int i=0; i<a[cv].size(); i++) {
			int v = a[cv][i].first, w = a[cv][i].second;
			if (!visit[v] && cu + w < dist[v]) {
				dist[v] = cu + w;
				pq.push(make_pair(v,dist[v]));
			}
		}
	}
	for (int i=1; i<=n; i++) {
		if (i==source)
			continue;
		for (int j=0; j<a[i].size(); j++) {
            if(a[i][j].first == source)
                continue;
			if (dist[i] + a[i][j].second == dist[j]) {
				pass[i] = true;
                printf("%d %d %d check\n", i, j, dist[j]);
            }
		}
	}
}


int main(int argc, char** argv) {
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	   그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	   또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	   단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	//freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;
	scanf("%d", &TC);	// cin 사용 가능
	for(test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.
        int n, m, x, y, w;
        scanf("%d%d", &n, &m);
		for (int i=0; i<m; i++) {
			scanf("%d%d%d",&x,&y,&w);
			a[x].push_back(make_pair(y,w));
			a[y].push_back(make_pair(x,w));
		}
        for (int i=1; i<=n; i++)
            pass[i] = false;
		for (int i=1; i<=n; i++)
			dijkstra(i,n);
		int cnt = 0;
		for (int i=1; i<=n; i++)
			if (!pass[i])
				cnt++;

		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);	// cout 사용 가능
		printf("%d\n",cnt);
		for (int i=1; i<=n; i++)
			if(!pass[i])
				printf("%d\n", i);
	}


	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}

