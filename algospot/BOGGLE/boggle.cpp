#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

char boggle[5][5];

bool find_word (int i, int j, const string& word) {

	if (word.empty())
		return true;
	if (i<0 || i>4 || j<0 || j>4)
		return false;
	if (word[0] != boggle[i][j])
		return false;
	int offX[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
	int offY[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
	for (int k=0; k<8; k++) {
		if (find_word (i+offX[k], j+offY[k], word.substr(1)))
			return true;
	}
	return false;
}

void find () {

	string inputString;
	cin >> inputString;

	for (int i=0; i<5; i++) {
		for (int j=0; j<5; j++) {
			if (find_word(i, j, inputString)) {
				cout << inputString << " YES" << endl;
				return;
			}
		}
	}
	cout << inputString << " NO" << endl;
}

int main() {
	int testNum;
	scanf("%d", &testNum);

	while(testNum--) {
		// get characters of boggle table
		for (int r=0; r<5; r++) {
			scanf("%s", boggle[r]);
		}

		int iteration;
		scanf("%d", &iteration);
		for (int i=0; i<iteration; i++) {
			find();
		}

	}
	return 0;
}
