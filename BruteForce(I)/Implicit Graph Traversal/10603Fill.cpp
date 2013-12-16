#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Data {
	vector<int> m_capability;
	int m_amount;
};

void GetResult (Data& data, int target, vector<int>& result) {
	queue<Data> q;
	Data initialState = data;
	initialState.m_capability[0] = 0;
	initialState.m_capability[1] = 0;
	q.push(initialState);
	vector< vector<bool> > visited(300, vector<bool>(300, false));
	while (!q.empty()) {
		Data thisElement = q.front();
		q.pop();
		visited[thisElement.m_capability[0]][thisElement.m_capability[1]] = true;
		for (int i = 0; i < 3; i++) {
			if (result[thisElement.m_capability[i]] == -1
				|| result[thisElement.m_capability[i]] > thisElement.m_amount) {
					result[thisElement.m_capability[i]] = thisElement.m_amount;
			}
		}
		
		// generate new states.
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i != j && thisElement.m_capability[i] != 0 && thisElement.m_capability[j] < data.m_capability[j]) {
					Data newElement = thisElement;
					int currentAmount;
					if (thisElement.m_capability[i] < data.m_capability[j] - thisElement.m_capability[j]) {
						currentAmount = thisElement.m_capability[i];
					} else {
						currentAmount = data.m_capability[j] - thisElement.m_capability[j];
					}
					newElement.m_capability[i] -= currentAmount;
					newElement.m_capability[j] += currentAmount;
					newElement.m_amount += currentAmount;
					if (!visited[newElement.m_capability[0]][newElement.m_capability[1]]) {
						q.push(newElement);
					}
				}
			}
		}
	}
}

int main() {
	int numOfCases;
	cin >> numOfCases;
	while (numOfCases--) {
		Data data;
		int target;
		data.m_capability.resize(3);
		for (int i = 0; i < 3; i++) {
			cin >> data.m_capability[i];
		}
		cin >> target;
		data.m_amount = 0;
		vector<int> result(300, -1);
		GetResult(data, target, result);
		for (int i = target; i >= 0; i++) {
			if (result[i] != -1) {
				cout << result[i] << " " << i << endl;
				break;
			}
		}
	}
}

// STRONGLY NEEDS REVIEW.
// 1. Review and remember this template.
// 2. Fix a logic bug for the original bug, the test case
//    for this problem on Uva is not strong, it doesn't judge
//    for the minimum output.
//