#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	int count = 0;
	while (true) {
		int n, q;
		cin >> n >> q;
		if (n == 0 && q == 0)
			break;
		cout << "CASE# " << ++count << ":" << endl;
		//vector<int> data(n);
		int* data = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> data[i];
		}
		sort(data, data + n);
		for (int i = 0; i < q; i++) {
			int query;
			cin >> query;
			//vector<int>::iterator resultPosition;
			int* resultPosition = lower_bound(data, data + n, query);
			if (resultPosition == data + n || *resultPosition != query) {
				cout << query << " not found" << endl;
			} else {
				cout << query << " found at " << resultPosition - data + 1 << endl;
			}
		}


		// The following are implementation for bucket sort method.
		//vector<int> hashTable(10001, 0);
		//for (int i = 0; i < n; i++) {
		//	int currentNumber;
		//	cin >> currentNumber;
		//	hashTable[currentNumber]++;
		//}

		//// Notice we can use a sum array to avoid duplicate 
		//// calculation.
		//vector<int> sumTable(10001, 0);
		//for (int i = 0; i < 10001; i++) {
		//	if (i == 0) {
		//		sumTable[i] = hashTable[i];
		//	} else {
		//		sumTable[i] = sumTable[i - 1] + hashTable[i];
		//	}
		//}

		//for (int i = 0; i < q; i++) {
		//	int query;
		//	cin >> query;
		//	if (hashTable[query]) {
		//		cout << query << " found at " << sumTable[query - 1] + 1 << endl;
		//	} else {
		//		cout << query << " not found" << endl;
		//	}
		//}
	}
}

//
// 1. Notice it is better to use bucket sort for this problem.
//


