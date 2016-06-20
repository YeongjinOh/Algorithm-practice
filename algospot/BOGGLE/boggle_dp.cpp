#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

char boggle[5][5];
int d[2][5][5]; // dynamic array to check match

// check 8-directional neighbors of the element at (i,j) with given 'value'
bool hasNeighbor (int r, int c, int value) {
	
	int offX[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
	int offY[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
	int x, y;
	for (int k=0; k<8; k++) {
		x = c + offX[k];
		y = r + offY[k];
		if (x>=0 && y>=0 && x<5 && y<5 && d[value%2][y][x] == value)
			return true;
	}
	return false;
}

void find () {

	string inputString;
	cin >> inputString;
	memset (d,0,sizeof(d));
	int size = inputString.size();

for (int i=0; i<size; i++) {
		for (int r=0; r<5; r++) {
			for (int c=0; c<5; c++) {
				if (hasNeighbor(r, c, i) && boggle[r][c] == inputString[i])
					d[(i+1)%2][r][c] = i+1;
			}
		}
	}
	for (int r=0; r<5; r++) {
		for (int c=0; c<5; c++) {
			if (d[size%2][r][c] == size) {
				cout << inputString << " YES" << endl;
				return ;
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
