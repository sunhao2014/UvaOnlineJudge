//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstdio>
//
//using namespace std;
//
//bool IsSorted (vector<int>& data, int n) {
//	bool result = true;
//	for (int i = 0; i < n - 1; i++) {
//		if (data[i] > data[i + 1]) {
//			result = false;
//		}
//	}
//	return result;
//}
//
//int GetSwapNum (vector<int>& data, int n, int& result) {
//	if (IsSorted(data, n)) {
//		result++;
//	} else {
//		for (int i = 0; i < n - 1; i++) {
//			if (data[i] > data[i + 1]) {  // if it is a inversion pair.
//				swap(data[i], data[i + 1]);
//				GetSwapNum(data, n, result);
//				swap(data[i], data[i + 1]);
//			}
//		}
//		return result;
//	}
//}
//
//int main() {
//	int currentCase = 1;
//	while (true) {
//		int n;
//		cin >> n;
//		if (n == 0) {
//			break;
//		}
//		vector<int> data(n);
//		for (int i = 0; i < n; i++) {
//			cin >> data[i];
//		}
//		int result = 0;
//		if (!IsSorted(data, n)) {
//			GetSwapNum(data, n, result);
//		}
//		printf("There are %d swap maps for input data set %d.\n", result, currentCase++);
//	}
//}
//
//// BLOCKED AT PHASE 1.
//// 1. Notice the problem needs us to swap ADJACENT elements.
//// 2. The recursive approach. How to define the recursion.
//// 3. The exit point of recursion and when to add the counter.
//// 4. Use global variable counter or reference? (They are the same.)
//// 5. Time complicity analysis.
////