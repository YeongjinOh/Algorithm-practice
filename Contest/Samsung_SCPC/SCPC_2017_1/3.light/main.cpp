/*
   You should use the statndard input/output

   in order to receive a score properly.

   Do not use file input and output

   Please be very careful.
   */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
    int T, test_case;
    /*
       The freopen function below opens input.txt file in read only mode, and afterward,
       the program will read from input.txt file instead of standard(keyboard) input.
       To test your program, you may save input data in input.txt file,
       and use freopen function to read from the file when using cin function.
       You may remove the comment symbols(//) in the below statement and use it.
       Use #include<cstdio> or #include <stdio.h> to use the function in your program.
       But before submission, you must remove the freopen function or rewrite comment symbols(//).
       */

    // freopen("input.txt", "r", stdin);

    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > g(40000), abase(n, vector<int> (m)), bbase(n, vector<int> (m));
        vector<vector<bool> > base(n, vector<bool> (m, false));
        // 0~9999 : R-true, 10000~19999 : R-false, 20000~29999 : C-true, 30000~39999 : C-false
        int r = 0, c = 0, ra = 0, cb = 0; // (r,c) of starting point
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int on, a, b;
                scanf("%d%d%d", &on, &a, &b);
                // index of R-true, R-false, C-true, C-false
                int rt = 100*i+a, rf = 10000 + rt;
                int ct = 20000 + 100*j+b, cf = 10000 + ct;
                abase[i][j] = a;
                bbase[i][j] = b;
                if (on) {
                    // (C && R) || (!C && !R)
                    // (!C || R) && (C || R)
                    g[rt].push_back(ct);
                    g[ct].push_back(rt);
                    g[rf].push_back(cf);
                    g[cf].push_back(rf);
//                    base[i][j] = true;
                } else {
                    // (!C && R) || (C && !R)
                    g[cf].push_back(rt);
                    g[rt].push_back(cf);
                    g[ct].push_back(rf);
                    g[rf].push_back(ct);
                    r = i, c = j; // update starting point
                    ra = a, cb = b;
                }
            }
        }
        vector<bool> ans(40000, false);
        bool successAll = true;
//        for (int i=0; i<n && successAll; i++) {
//            for (int j=0; j<m && successAll; j++) {
          for (int i=0; i<1; i++) { for (int j=0; j<1; j++) {
//                if (base[i][j]) continue;
                int rt = 100*i + abase[i][j], rf = 10000 + rt;
                int ct = 20000 + 100*j + bbase[i][j], cf = 10000 + ct;
                /* check (!C && R) */
                vector<bool> visit(40000, false);
                queue<int> st;
                vector<int> res;
                vector<pair<int, int> > pos; // visit post
                st.push(cf);
                visit[cf] = true;
                bool success = true;
                while (!st.empty()) {
                    int here = st.front(); st.pop();
                    res.push_back(here);
                    if (here < 10000 || (20000 <= here && here < 30000)) {
                        if (visit[here+10000]) {
                            success = false;
                            break;
                        }
                    } else {
                        if (visit[here-10000]) {
                            success = false;
                            break;
                        }
                    }
                    for (int i=0; i<g[here].size(); i++) {
                        int there = g[here][i];
                        if (!visit[there]) {
                            visit[there] = true;
                            if (here < 20000) {
                                pos.push_back(make_pair((here%10000)/100, (there%10000)/100));
                            } else {
                                pos.push_back(make_pair((there%10000)/100, (here%10000)/100));
                            }
                            st.push(there);
                        }
                    }
                }
                if (success) {
                    for (int k=0; k<res.size(); k++) {
                        ans[res[k]] = true;
                    }
                    for (int k=0; k<pos.size(); k++) {
                        int i = pos[k].first, j = pos[k].second;
                        base[i][j] = true;
                    }
                    continue;
                }

                /* check (C && !R) */
                visit = vector<bool> (40000, false);
                res.clear(); pos.clear();
                st.push(rf);
                visit[rf] = true;
                success = true;
                while (!st.empty()) {
                    int here = st.front(); st.pop();
                    res.push_back(here);
                    if (here < 10000 || (20000 <= here && here < 30000)) {
                        if (visit[here+10000]) {
                            success = false;
                            break;
                        }
                    } else {
                        if (visit[here-10000]) {
                            success = false;
                            break;
                        }
                    }
                    for (int i=0; i<g[here].size(); i++) {
                        int there = g[here][i];
                        if (!visit[there]) {
                            visit[there] = true;
                            if (here < 20000) {
                                pos.push_back(make_pair((here%10000)/100, (there%10000)/100));
                            } else {
                                pos.push_back(make_pair((there%10000)/100, (here%10000)/100));
                            }
                            st.push(there);
                        }
                    }
                }
                if (success) {
                     for (int k=0; k<res.size(); k++) {
                        ans[res[k]] = true;
                    }
                    for (int k=0; k<pos.size(); k++) {
                        int i = pos[k].first, j = pos[k].second;
                        base[i][j] = true;
                    }
                    continue;
                }
                successAll = false;
            }
        }

        printf("Case #%d\n", test_case+1);
        if (successAll) {
        for (int here=0; here<10000; here++) {
            if (!ans[here]) continue;
            printf("R%04d ", here%10000);
        }
        for (int here=20000; here<30000; here++) {
            if (!ans[here]) continue;
            printf("C%04d ", here%10000);
        }
        printf("\n");
        } else {
            printf("Impossible\n");
        }
   }

    return 0;//Your program should return 0 on normal termination.
}
