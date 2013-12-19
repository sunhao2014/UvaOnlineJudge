#include <vector>
#include <iostream>

using namespace std;

int main () {
	int numOfCases;
	cin >> numOfCases;
	while (numOfCases--) {
		int dayCount;
		cin >> dayCount;
		vector<int> flags(dayCount + 1, true);
		int partyCount;
		cin >> partyCount;
		for (int i = 0; i < partyCount; i++) {
			int currentH;
			cin >> currentH;
			int temp = currentH;
			while (temp <= dayCount) {
				flags[temp] = false;
				temp += currentH; 
			}
		}
		int totalCount = 0;
		for (int i = 1; i <= dayCount; i++) {
			if (!flags[i] && i % 7 != 6 && i % 7 != 0) {
				totalCount++;
			}
		}
		cout << totalCount << endl;
	}
}