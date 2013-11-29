#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

int main () {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		vector< vector<char> > data(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				char temp;
				cin >> temp;
				if (temp == '\n')
					cin >> temp;
				data[i].push_back(temp);
			}
		}
		int total = pow(2, n * n);

		// try every cases.
		int maxRooks = 0;
		for (int i = 1; i < total; i++) {
			bitset<16> currentBitset(i);
			// generate solution matrix.
			vector< vector<int> > solution(n);
			int currentIndex = 0;

			bool isNotConflictWithWall = true;
			for (int j = 0; j < n && isNotConflictWithWall; j++) {
				for (int k = 0; k < n && isNotConflictWithWall; k++) {
					if (currentBitset[currentIndex] == 1 && data[j][k] == 'X') {
						isNotConflictWithWall = false;
					} else {
						solution[j].push_back(currentBitset[currentIndex++]);
					}
				}
			}

			if (!isNotConflictWithWall) {
				continue;
			}

			// check for every row and every column.
			bool isLegal = true;
			for (int j = 0; j < n && isLegal; j++) {
				bool hasOneElement = false;   // 1..0..1..0 is OK.
				for (int k = 0; k < n && isLegal; k++) {
					if (data[j][k] == 'X') {
						hasOneElement = false;
					} else if (solution[j][k] == 1 && hasOneElement) {
						isLegal = false;
					} else if (solution[j][k] == 1 && !hasOneElement) {
						hasOneElement = true;
					}
				}
			}
			if (isLegal) {
				for (int k = 0; k < n && isLegal; k++) {
					bool hasOneElement = false;   // 1..0..1..0 is OK.
					for (int j = 0; j < n && isLegal; j++) {
						if (data[j][k] == 'X') {
							hasOneElement = false;
						} else if (solution[j][k] == 1 && hasOneElement) {
							isLegal = false;
						} else if (solution[j][k] == 1 && !hasOneElement) {
							hasOneElement = true;
						}
					}
				}
			}

			if (isLegal) {
				int currentRookCount = 0;
				for (int i = 0; i < 16; i++) {
					currentRookCount += currentBitset[i];
				}
				if (currentRookCount > maxRooks) {
					maxRooks = currentRookCount;
				}
			}
		}
		cout << maxRooks << endl;
	}
}

//
// 1. Notice the initial value of 'maxRooks' should be 0, if
//    it is -1, sometimes it will give the wrong answer.
//