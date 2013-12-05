#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

void GetMaxScore (vector<int>& currentResult, const vector< vector<int> >& data, int current, int n, int& maxScore) {
	if (current == n) {
		int currentScore = 0;
		for (int i = 0; i < 8; i++) {
			currentScore += data[i][currentResult[i]];
		}
		if (currentScore > maxScore) {
			maxScore = currentScore;
		}
	} else {
		for (int i = 0; i < 8; i++) {
			bool canBePlaced = true;
			// have made a mistake - wrote "j" for "current".
			for (int j = 0; j < current; j++) {
				if ((currentResult[j] == i) || (j - currentResult[j] == current - i) || (j + currentResult[j] == current + i)) {
					canBePlaced = false;
				}
			}
			if (canBePlaced) {
				currentResult[current] = i;
				GetMaxScore(currentResult, data, current + 1, n, maxScore);
			}
		}
	}
}

int main() {
	int numOfCases;
	cin >> numOfCases;
	while (numOfCases--) {
		vector< vector<int> > data(8, vector<int>(8));
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> data[i][j];
			}
		}
		int maxScore = 0;
		vector<int> currentResult(8, -1);
		GetMaxScore(currentResult, data, 0, 8, maxScore);
		printf("%5d", maxScore);
	}
}