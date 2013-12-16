#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#define MOVE 1
#define SWITH_ON 2
#define SWITH_OFF 3

struct Action {
	int m_action;
	int m_target;
};

struct State {
	int m_currentRoom;
	vector<bool> m_lightStatus;
	vector<Action> m_actionList;
};

map<string, int> hashMap;
int r, d, s;

bool IsFinalState (const State& state) {
	if (state.m_currentRoom != r) {
		return false;
	}
	for (int i = 1; i < r; i++) {
		if (state.m_lightStatus[i]) {
			return false;
		}
	}
	if (!state.m_lightStatus[r]) {
		return false;
	}
	return true;
}

bool IsExist(const State& state) {
	string temp;
	temp += (char)(state.m_currentRoom + '0');
	for (int i = 1; i <= r; i++) {
		int currentLightState;
		if (state.m_lightStatus[i]) {
			currentLightState = 1;
		} else {
			currentLightState = 0;
		}
		temp += (char)(currentLightState + '0');
	}
	if (hashMap.count(temp) == 0) {
		hashMap[temp] = 1;
		return false;
	} else {
		return true;
	}
}

bool HaveSolution (State& initialState, const vector< vector<bool> >& edges, const vector< vector<bool> >& swithes, State& solutionState) {
	queue<State> q;
	q.push(initialState);
	IsExist(initialState);
	while (!q.empty()) {
		State currentState = q.front();
		q.pop();
		if (IsFinalState(currentState)) {
			solutionState = currentState;
			return true;
		}

		// move on to the next room.
		for (int i = 1; i < edges.size(); i++) {
			if (currentState.m_currentRoom != i && edges[currentState.m_currentRoom][i] && currentState.m_lightStatus[i]) { // don't forget to check the light status.
				State nextState = currentState;
				nextState.m_currentRoom = i;
				if (!IsExist(nextState)) {
					Action currentAction;
					currentAction.m_action = MOVE;
					currentAction.m_target = i;
					nextState.m_actionList.push_back(currentAction);
					q.push(nextState);
				}
			}
		}

		// turn on/off the light.
		for (int i = 1; i < swithes.size(); i++) {
			if (currentState.m_currentRoom != i && swithes[currentState.m_currentRoom][i]) {
				State nextState = currentState;
				Action currentAction;
				if (currentState.m_lightStatus[i]) {
					nextState.m_lightStatus[i] = false;
					if (!IsExist(nextState)) {
						currentAction.m_action = SWITH_OFF;
						currentAction.m_target = i;
						nextState.m_actionList.push_back(currentAction);
						q.push(nextState);
					}
				} else {
					nextState.m_lightStatus[i] = true;
					if (!IsExist(nextState)) {
						currentAction.m_action = SWITH_ON;
						currentAction.m_target = i;
						nextState.m_actionList.push_back(currentAction);
						q.push(nextState);
					}
				}
			}
		}
	}
	return false;
}
int main () {
	int count = 1;
	while (true) {
		cin >> r >> d >> s;
		if (r == 0 && d == 0 && s == 0) {
			break;
		}
		hashMap.clear();  // don't forget to clear the global variables!!!
		vector< vector<bool> > edges(r + 1, vector<bool>(r + 1, false));
		vector< vector<bool> > swithes(r + 1, vector<bool>(r + 1, false));
		for (int i = 0; i < d; i++) {
			int x, y;
			cin >> x >> y;
			edges[x][y] = true;
			edges[y][x] = true;
		}
		for (int i = 0; i < s; i++) {
			int x, y;
			cin >> x >> y;
			swithes[x][y] = true;
		}
		State initialState;
		initialState.m_currentRoom = 1;
		for (int i = 0; i <= r; i++) {
			if (i == 1) {
				initialState.m_lightStatus.push_back(true);
			} else {
				initialState.m_lightStatus.push_back(false);
			}
		}
		State solutionState;
		cout << "Villa #" << count++ << endl;
		if (HaveSolution(initialState, edges, swithes, solutionState)) {
			int numOfSteps = solutionState.m_actionList.size();
			cout << "The problem can be solved in " << numOfSteps << " steps:" << endl;
			for (int i = 0; i < numOfSteps; i++) {
				switch (solutionState.m_actionList[i].m_action) {
				case MOVE:
					cout << "- Move to room " << solutionState.m_actionList[i].m_target << "." << endl;
					break;
				case SWITH_ON:
					cout << "- Switch on light in room " << solutionState.m_actionList[i].m_target << "." << endl;
					break;
				case SWITH_OFF:
					cout << "- Switch off light in room " << solutionState.m_actionList[i].m_target << "." << endl;
					break;
				default:
					break;
				}
			}
		} else {
			cout << "The problem cannot be solved." << endl;
		}
		cout << endl;
	}
}

//
// 1. Don't forget to clear the global variables!!
//