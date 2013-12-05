#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool IsSum23 (vector<int>& operatorResult, const vector<int>& data, int current, int n) {
	if (current == n) {
		int tempResult = data[0];
		for (int i = 0; i < n; i++) {
			switch (operatorResult[i]) {
			case 0: // +
				tempResult += data[i + 1];
				break;
			case 1: // - 
				tempResult -= data[i + 1];
				break;
			case 2: // *
				tempResult *= data[i + 1];
				break;
			default:
				break;
			}
		}
		if (tempResult == 23) {
			return true;
		} else {
			return false;
		}
	} else {
		for (int i = 0; i < 3; i++) {
			operatorResult[current] = i;
			if (IsSum23(operatorResult, data, current + 1, n)) {
				return true;
			}
		}
		// Notice we need a return statement here, otherwise the 
		// logic is not complete.
		return false;
	}
}

int main() {
	while (true) {
		vector<int> data;
		bool shouldTerminate = true;
		for (int i = 0; i < 5; i++) {
			int thisNumber;
			cin >> thisNumber;
			if (thisNumber != 0) {
				shouldTerminate = false;
			}
			data.push_back(thisNumber);
		}
		if (shouldTerminate) {
			break;
		}

		// Notice: must sort the array before the permutation!
		sort(data.begin(), data.end());
		bool isSum23 = false;
		do {
			vector<int> operatorResult(4);
			if (IsSum23(operatorResult, data, 0, 4)) {
				cout << "Possible" << endl;
				isSum23 = true;
				break;
			}
		} while (next_permutation(data.begin(), data.end()));

		if (!isSum23) {
			cout << "Impossible" << endl;
		}
	}
}

/*
1. See the comments inline, there are two detected bugs.
*/