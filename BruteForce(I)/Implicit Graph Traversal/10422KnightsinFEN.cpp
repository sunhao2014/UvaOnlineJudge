#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int steps[8][2] = {
	{-2, -1},    // originally mistook . for , see comments.
	{-1, -2},
	{-2, 1},
	{-1, 2},
	{2, -1},
	{1, -2},
	{2, 1},
	{1, 2}
};

bool IsFinal (const vector< vector<char> >& data) {
	char finalResult[5][5] = {
		{'1', '1', '1', '1', '1'}, 
		{'0', '1', '1', '1', '1'}, 
		{'0', '0', ' ', '1', '1'}, 
		{'0', '0', '0', '0', '1'}, 
		{'0', '0', '0', '0', '0'}
	};
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (data[i][j] != finalResult[i][j]) {
				return false;
			}
		}
	}
	return true;
}

bool HaveSolution (vector< vector<char> >& data, int current, int maxLevel, int x, int y) {
	if (current > maxLevel) {
		return false;
	} else {
		if (IsFinal(data)) {
			return true;
		} else {
			for (int i = 0; i < 8; i++) {
				int newX = x + steps[i][0];
				int newY = y + steps[i][1];
				if (newX < 0 || newX > 4 || newY < 0 || newY > 4) {
					continue;
				}
				swap(data[x][y], data[newX][newY]);
				if (HaveSolution(data, current + 1, maxLevel, newX, newY)) {
					return true;
				}
				swap(data[x][y], data[newX][newY]);
			}
			return false;
		}
	}
}

int main() {
	int numOfCases;
	scanf("%d", &numOfCases);
	getchar();
	while (numOfCases--) {
		vector< vector<char> > data(5, vector<char>(5));
		int x = -1, y = 1;
		int count0 = 0;
		int count1 = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				data[i][j] = getchar();
				if (data[i][j] == ' ') {
					x = i;
					y = j;
				} else if (data[i][j] == '1'){
					count1++;
				} else {
					count0++;
				}
			}
			getchar();
		}
		if (x == -1 || y == -1 || count0 != count1) {
			cout << "Unsolvable in less than 11 move(s)." << endl;
		} else {
			if (IsFinal(data)) {
				cout << "Solvable in 0 move(s)." << endl; 
			} else {
				bool haveSolution = false;
				for (int maxLevel = 1; maxLevel <= 10; maxLevel++) {
					if (HaveSolution(data, 0, maxLevel, x, y)) {
						cout << "Solvable in " << maxLevel << " move(s)." << endl; 
						haveSolution = true;
						break;
					}
				}
				if (!haveSolution) {
					cout << "Unsolvable in less than 11 move(s)." << endl;
				}
			}
		}
	}
}

//
// 1. This problem can also be solve by BFS + Hash.
// 2. For the inline bug, the sample input is correct, but
//    using Uva tools (http://uvatoolkit.com/problemssolve.php),
//    this has been solved. The following case cannot pass
//		1
//		11111
//		01111
//		00011
//		00001
//		 0000