#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct State {
	vector< vector<int> > m_data;
	int m_x;   // the position of 0.
	int m_y;
	string m_transformSequence;
};

bool IsExist (const State& state, map<string, int>& stateHash) {
	string temp = "";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			char thisChar = state.m_data[i][j] + '0';
			temp += thisChar;
		}
	}
	if (stateHash.count(temp) == 0) {
		stateHash[temp] = 1;
		return false;
	} else {
		return true;
	}
}

void GetMaxResult (const State& data, State& maxResult) {
	queue<State> q;
	q.push(data);
	map<string, int> stateHash;
	IsExist(data, stateHash);
	while (!q.empty()) {
		State thisElement = q.front();
		q.pop();
		if (thisElement.m_transformSequence.length() > maxResult.m_transformSequence.length()) {
			maxResult = thisElement;
		}
		State newStateLeft = thisElement;
		State newStateTop = thisElement;
		State newStateRight =  thisElement;
		State newStateBottom = thisElement;

		if (newStateTop.m_x != 0) {
			swap(newStateTop.m_data[newStateTop.m_x][newStateTop.m_y], newStateTop.m_data[newStateTop.m_x - 1][newStateTop.m_y]);
			if (!IsExist(newStateTop, stateHash)) {
				newStateTop.m_x--;
				string temp = "U";
				newStateTop.m_transformSequence += temp;
				q.push(newStateTop);
			}
		}
		if (newStateRight.m_y != 2) {
			swap(newStateRight.m_data[newStateRight.m_x][newStateRight.m_y], newStateRight.m_data[newStateRight.m_x][newStateRight.m_y + 1]);
			if (!IsExist(newStateRight, stateHash)) {
				newStateRight.m_y++;
				string temp = "R";
				newStateRight.m_transformSequence += temp;
				q.push(newStateRight);
			}
		}
		if (newStateBottom.m_x != 2) {
			swap(newStateBottom.m_data[newStateBottom.m_x][newStateBottom.m_y], newStateBottom.m_data[newStateBottom.m_x + 1][newStateBottom.m_y]);
			if (!IsExist(newStateBottom, stateHash)) {
				newStateBottom.m_x++;
				string temp = "D";
				newStateBottom.m_transformSequence += temp;
				q.push(newStateBottom);
			}
		}
		if (newStateLeft.m_y != 0) {
			swap(newStateLeft.m_data[newStateLeft.m_x][newStateLeft.m_y], newStateLeft.m_data[newStateLeft.m_x][newStateLeft.m_y - 1]);
			if (!IsExist(newStateLeft, stateHash)) {
				newStateLeft.m_y--;
				string temp = "L";
				newStateLeft.m_transformSequence += temp;
				q.push(newStateLeft);
			}
		}
	}
}

int main() {
	int numOfCases;
	int count = 1;
	cin >> numOfCases;
	while (numOfCases--) {
		State data;
		data.m_data.resize(3);
		data.m_transformSequence = "";
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				int temp;
				cin >> temp;
				if (temp == 0) {
					data.m_x = i;
					data.m_y = j;
				}
				data.m_data[i].push_back(temp);
			}
		}
		State maxResult;
		maxResult.m_transformSequence = "";
		GetMaxResult(data, maxResult);
		cout << "Puzzle #" << count++ << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (j == 2) {
					cout << maxResult.m_data[i][j];
				} else {
					cout << maxResult.m_data[i][j] << " ";
				}
			}
			cout << endl;
		}
		cout << maxResult.m_transformSequence << endl;
	}
}

//
// 1. How to judge if the element is already exist in a map?
//