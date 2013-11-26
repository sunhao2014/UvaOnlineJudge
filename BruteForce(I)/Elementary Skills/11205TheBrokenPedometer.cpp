#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int numOfCases;
	cin >> numOfCases;
	while (numOfCases--) {
		int p, n;
		cin >> p >> n;
		vector< vector<int> > data(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < p; j++) {
				int currData;
				cin >> currData;
				data[i].push_back(currData);
			}
		}

		int minLEDNum = p;
		// Notice the loop control conditions there. We can use "j < n && canBeDeleted"
		// in a for loop in order to save some bool variables. Also notice the usage of
		// the two bool variables, make the logic clear first. Then don't forget to check
		// j != k, this is critical, forget to add this will case a fatal logic error.
		//
		// NOTICE: This part of logic is beautiful, needs serveral times review.
		//
		for (int i = 1; i <= p; i++) {
			// generate the bit vector with i "1"s.
			vector<int> bitVector(p, 0);
			for (int j = 0; j < i; j++) {
				bitVector[p - 1 - j] = 1;
			}
			bool canDeleteIElements = false;
			do {
				bool canBeDeleted = true;
				for (int j = 0; j < n && canBeDeleted; j++) {
					for (int k = 0; k < n && canBeDeleted; k++) {
						if (j != k) {
							bool isIdentical = true;
							for (int q = 0; q < p; q++) {
								if (bitVector[q] == 0 && data[j][q] != data[k][q]) {
									isIdentical = false;
								}
							}
							if (isIdentical) {
								canBeDeleted = false;
							}
						}
					}
				}
				if (canBeDeleted) {
					canDeleteIElements = true;
					break;
				}
			} while (next_permutation(bitVector.begin(), bitVector.end()));
			if (!canDeleteIElements) {
				break;
			} else {
				minLEDNum = p - i;
			}
		}
		cout << minLEDNum << endl;
	}
}

/*
1. Review the logic control, see inline.
*/