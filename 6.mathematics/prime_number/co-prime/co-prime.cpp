#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
#define MAX_PRIME 32000
bool prime[MAX_PRIME+1]; // false if prime
vector<int> divider;
// count number of integers divided by p between a and b
long long count (long long a, long long b, int p) {
    return (long long)(b/p) - (long long)((a-1)/p);
}

// recursive cur : current index, m : how many elements left to be multiplied
long long get_helper (long long a, long long b, int cur, int m, long long mult) {
    if (divider.size()-cur < m)
        return 0;
    if (m==1)
        return count(a,b,mult*divider[cur]);
    long long sum = 0;
    for (int i=cur+1; i<divider.size(); i++)
        sum += get_helper(a,b,i,m-1,mult*divider[cur]);
    return sum;
}

long long get (long long a, long long b, int m) {
    long long sum = 0;
    for (int i=0; i<divider.size(); i++)
        sum += get_helper(a, b, i, m, 1);
    return sum;
}

long long getAll (long long a, long long b) {
    long long sum=b-a+1;
    for (int i=1; i<=divider.size(); i++) {
        if (i%2 == 0)
            sum += get(a, b, i);
        else
            sum -= get(a, b, i);
    }
    return sum;
}

int main () {

    // generate prime numbers
    prime[0] = true;
    prime[1] = true;
    for (int i=2; i*i<=MAX_PRIME; i++)
        if(!prime[i]) {
            int j;
            for (j=i*i; j<=MAX_PRIME; j+=i)
                prime[j]=true;
        }

    int t;
    scanf("%d",&t);
    for(int test_case=1; test_case<=t; test_case++) {
        long long a,b,n;
        scanf("%lld%lld%lld",&a,&b,&n);
        divider.clear();
        long long cur=n;
        // push all prime divider of n
        for (int i=2; i*i<=n; i++) {
            if (!prime[i]) {
                if(cur % i == 0) {
                    divider.push_back(i);
                    while(cur%i == 0) {
                        cur = cur/i;
                    }
                    if (cur==1)
                        break;
                }
            }
        }
        if (cur != 1)
            divider.push_back(cur);

        printf("Case #%d: %lld\n",test_case,getAll(a,b));
    }
    return 0;
}
