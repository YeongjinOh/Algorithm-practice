#include <iostream>
#include <vector>
#include <unordered_map>
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
vector<int> prime;

void fillDivisors(int idx, int factor, vector<pii>& pp, vector<int>& divisors) {
    if (idx == pp.size()) {
        divisors.pb(factor);
        return;
    }
    int mult = 1;
    for (int i=0; i<=pp[idx].second; i++) {
        fillDivisors(idx+1, factor*mult, pp, divisors);
        mult *= pp[idx].first;
    }
}

void getDivisors (int num, vector<int> &divisors) {
    vector<pii> pp; // prime pairs
    for (int i=0; i<prime.size() && num > 1; ++i) {
        int p = prime[i];
        int pwr = 0;
        while (num%p == 0) {
            num/=p;
            pwr++;
        }
        if (pwr > 0)
            pp.pb(mp(p,pwr));
    }
    if (num > 1)
        pp.pb(mp(num,1));
    fillDivisors(0, 1, pp, divisors);
}

bool checkRange(vector<pii> &vpii, int l, int r) {
    if (vpii.empty() || vpii.back().second<l) return true;
    int lo = 0, hi = vpii.size()-1;
    while (lo < hi) {
        int mid = (lo+hi)/2;
        if (vpii[mid].second >= l) hi=mid;
        else lo = mid+1;
    }
    return vpii[lo].first > r;
}

int main(int argc, char** argv)
{
    int T, test_case;
    // build prime
    vector<bool> isPrime(1e6+10, true);
    isPrime[0] = isPrime[1] = false;
    for (int p=2; p*p<=1e6; p++) {
        if (isPrime[p]) {
            prime.push_back(p);
            for (int j=p*p; j<=1e6; j+=p)
                isPrime[j] = false;
        }
    }
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        int n, m;
        cin >> n >> m;
        // (prime, power) -> list of range [a1,b1], [a2,b2], ...
        unordered_map<int, vector<pii> > ump;
        long long sum = 0;
        for (int i=1; i<=n; ++i) {
            int num;
            cin >> num;
//            scanf("%d", &num);
            vector<int> divisors;
            getDivisors(num, divisors);
            for (int j=1; j<divisors.size(); ++j) {
                vector<pii> &vpii = ump[divisors[j]];
                if (!vpii.empty() && vpii.back().second == i-1) {
                    vpii.back().second = i;
                } else {
                    vpii.pb(mp(i,i));
                }
                /*
                printf("%d : ", divisors[j]);
                for (int s=0; s<vpii.size(); s++)
                    printf("[%d,%d] ", vpii[s].first, vpii[s].second);
                printf("\n");
                */
            }
        }
        for (int i=0; i<m; ++i) {
            int b, l, r;
            cin >> b >> l >> r;
//            scanf("%d%d%d", &b, &l, &r);
            vector<int> divisors;
            getDivisors(b, divisors);
            for (int j=1; j<divisors.size(); ++j) {
                vector<pii> &vpii = ump[divisors[j]];
                if (checkRange(vpii, l, r)) {
                    sum++;
                }
            }
        }
        cout << "Case #" << test_case+1 << endl;
        cout << sum << endl;
    }

    return 0;//Your program should return 0 on normal termination.
}
