#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Data {
	int m_x;
	int m_y;
	char m_operation;
};

int main () {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		vector<Data> data(2 * n);
		vector< vector<int> > board(n + 2, vector<int>(n + 2, 0));
		for (int i = 0; i < 2 * n; i++) {
			cin >> data[i].m_x;
			cin >> data[i].m_y;
			cin >> data[i].m_operation;
		}
		bool isWin = false;
		map<string, int> hashMap;
		int i;
		for (i = 0; i < 2 * n; i++) {
			if (data[i].m_operation == '+') {
				board[data[i].m_x][data[i].m_y] = 1;
			} else {
				board[data[i].m_x][data[i].m_y] = 0;
			}

			// judge the 4 cases.
			string stateString = "";
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					char temp = board[j][k] + '0';
					stateString += temp;
				}
			}
			if (hashMap.count(stateString) != 0) {
				isWin = true;
				break;
			}
			stateString = "";
			for (int j = 1; j <= n; j++) {
				for (int k = n; k >= 1; k--) {
					char temp = board[k][j] + '0';
					stateString += temp;
				}
			}
			if (hashMap.count(stateString) != 0) {
				isWin = true;
				break;
			}
			stateString = "";
			for (int j = n; j >= 1; j--) {
				for (int k = n; k >= 1; k--) {
					char temp = board[j][k] + '0';
					stateString += temp;
				}
			}
			if (hashMap.count(stateString) != 0) {
				isWin = true;
				break;
			}
			stateString = "";
			for (int j = n; j >= 1; j--) {
				for (int k = 1; k <= n; k++) {
					char temp = board[k][j] + '0';
					stateString += temp;
				}
			}
			if (hashMap.count(stateString) != 0) {
				isWin = true;
				break;
			}
			hashMap[stateString] = 1;
		}
		if (!isWin) {
			cout << "Draw" << endl;
		} else {
			int winPlayer;
			if (i % 2 == 0) {
				winPlayer = 2;
			} else {
				winPlayer = 1;
			}
			cout << "Player " << winPlayer << " wins on move " << ++i << endl;
		}
	}
}