#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main () {
	while (true) {
		vector< stack<string> > data(52);
		bool isValidCase = true;
		for (int i = 0; i < 52; i++) {
			string currentInput;
			cin >> currentInput;
			if (i == 0 && currentInput == "#") {
				isValidCase = false;
				break;
			}
			data[i].push(currentInput);
		}
		if (!isValidCase) {
			break;
		}
		for (int i = 1; i < 52; i++) {
			bool needContinue = true;
			while (needContinue) {
				needContinue = false;
				for (int j = 1; j <= i; j++) {  // "j > 0" not "j >= 0".
					if (data[j].empty()) {
						continue;
					}
					bool haveLeftThree = false;
					int currentIndex = j - 1;
					int currentCount = 0;
					while (currentIndex >= 0) {
						if (!data[currentIndex].empty()) {
							currentCount++;
							if (currentCount == 3) {
								haveLeftThree = true;
								break;
							}
						}
						currentIndex--;
					}
					if (haveLeftThree && (data[currentIndex].top()[0] == data[j].top()[0] || data[currentIndex].top()[1] == data[j].top()[1])) {
						needContinue = true;
						data[currentIndex].push(data[j].top());
						data[j].pop();
						break;
					}
					currentIndex = j - 1;
					bool haveLeftOne = false;
					while (currentIndex >= 0) {
						if (!data[currentIndex].empty()) {
							haveLeftOne = true;
							break;
						}
						currentIndex--;
					}
					if (haveLeftOne && (data[currentIndex].top()[0] == data[j].top()[0] || data[currentIndex].top()[1] == data[j].top()[1])) {
						needContinue = true;
						data[currentIndex].push(data[j].top());
						data[j].pop();
						break;
					}
				}
			}
		}
		int remainingCount = 0;
		for (int i = 0; i < 52; i++) {
			if (!data[i].empty()) {
				remainingCount++;
			}
		}
		if (remainingCount == 1) {
			cout << remainingCount << " pile remaining:";
		} else {
			cout << remainingCount << " piles remaining:";
		}

		for (int i = 0; i < 52; i++) {
			if (!data[i].empty()) {
				cout << " " << data[i].size();
			}
		}
		cout << endl;
	}
}