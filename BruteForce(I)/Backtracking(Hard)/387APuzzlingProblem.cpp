#include <iostream>
#include <vector>

using namespace std;

vector< vector< vector<int> > > data;

void GetSolution (vector< vector<int> >& result, int curreent, int n, bool& hasSolution) {
	if (hasSolution) {
		return;
	}
	if (curreent == n) {
		bool isValid = true;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (result[i][j] == 0) {
					isValid = false;
				}
			}
		}

		if (isValid) {
			hasSolution = true;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					cout << result[i][j];
				}
				cout << endl;
			}
		}
	} else {
		int x = data[curreent].size();
		int y = data[curreent][0].size();
		for (int i = 0; i < 4 - x + 1; i++) {
			for (int j = 0; j < 4 - y + 1; j++) {
				// judge whether we can place this brick on the position
				// which upper left point is (i, j).
				bool canPlace = true;
				for (int a = 0; a < x && canPlace; a++) {
					for (int b = 0; b < y; b++) {
						if (data[curreent][a][b] == 1 && result[i + a][j + b] != 0) {
							canPlace = false;
							break;
						}
					}
				}
				if (canPlace) {
					for (int a = 0; a < x; a++) {
						for (int b = 0; b < y; b++) {
							if (data[curreent][a][b] == 1) {
								result[i + a][j + b] = curreent + 1;
							}
						}
					}
					GetSolution(result, curreent + 1, n, hasSolution);
					for (int a = 0; a < x; a++) {
						for (int b = 0; b < y; b++) {
							if (data[curreent][a][b] == 1) {
								result[i + a][j + b] = 0;
							}
						}
					}
				}
			}
		}
	}
}

int main () {
	int currentCount = 0;
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		if (currentCount != 0) {
			cout << endl;
		}
		currentCount++;
		data.clear();
		data.resize(n);
		int x, y;
		for (int p = 0; p < n; p++) {
			cin >> x >> y;
			for (int i = 0; i < x; i++) {
				vector<int> temp;
				for (int j = 0; j < y; j++) {
					char number;
					cin >> number;
					temp.push_back((int)(number - '0'));
				}
				data[p].push_back(temp);
			}
		}
		vector< vector<int> > result(4, vector<int>(4, 0));
		bool hasSolution = false;
		GetSolution(result, 0, n, hasSolution);
		if (!hasSolution) {
			cout << "No solution possible" << endl;
		}
	}
}
