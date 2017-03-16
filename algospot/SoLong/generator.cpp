#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;
int C;

#define LEN 26

int main() {
    srand (time(NULL));

    int n = 100, l = 10;
    vector<string> words;
    for (int i=0; i<n; i++) {
        string word = "";
        int num = rand()%l+1;
        for (int j=0; j<num; j++) {
            word += ('A' + rand()%LEN);
        }
        words.push_back(word);
    }
    sort( words.begin(), words.end() );
    words.erase( unique( words.begin(), words.end() ), words.end() );
    for (int i=0; i<words.size(); i++) {
        printf("%d %s\n",i, words[i].c_str());
    }
    return 0;
}
