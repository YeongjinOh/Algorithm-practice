#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int  N, M;

    //get cards
    cin >> N;
    vector<int> cards;
    int card;
    while (N--) {
        scanf("%d",&card);
        cards.push_back(card);
    }
    sort(cards.begin(),cards.end());

    // get numbers
    cin >> M;
    int num;

    // binary search
    while (M--) {
        int l=0, r=cards.size()-1, mid=(l+r)/2;
        scanf("%d",&num);
        while (l!=r) {
            if (cards[mid] < num) l = mid+1;
            else r = mid;
            // mid should go left
            mid = (l+r)/2;
        }
        printf("%d ", cards[l] == num);
    }
    return 0;
}
