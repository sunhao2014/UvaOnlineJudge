//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//bool GetResult (vector<int>& counter, int pos) {
//	int currentNum;
//	cin >> currentNum;
//	if (currentNum == -1) {
//		return false;
//	}
//	counter[pos] += currentNum;
//	GetResult(counter, pos - 1);
//	GetResult(counter, pos + 1);
//	return true;
//}
//
//int main() {
//	int count = 1;
//	while (true) {
//		vector<int> counter(105, 0);
//		if (!GetResult(counter, 40)) {
//			break;
//		}
//		cout << "Case " << count++ << ":" << endl;
//		bool isFirstElement = true;
//		for (int i = 0; i < 100; i++) {
//			if (counter[i] != 0) {
//				if (isFirstElement) {
//					cout << counter[i];
//					isFirstElement = false;
//				} else {
//					cout << " " << counter[i];
//				}
//			}
//		}
//		cout << endl << endl;
//	}
//}