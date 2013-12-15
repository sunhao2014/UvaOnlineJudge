#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

//bool GetMinResult (vector<int>& currentResult, int current, int target, int& minLength, vector<int>& minResult) {
//	if (current > minLength) {
//		return false;     // key pruning point.
//	}
//
//	vector<bool> flags(10002, false);
//	for (int i = 0; i < current; i++) {
//		flags[currentResult[i]] = true;
//		for (int j = i; j < current; j++) {
//			if (currentResult[j] + currentResult[i] <= target) {
//				flags[currentResult[j] + currentResult[i]] = true;
//			}
//		}
//	}
//
//	if (flags[target]) {
//		if (current < minLength) {
//			minLength = current;
//			minResult = currentResult;
//		}
//		return true;  // the return value means whether it is the last level.
//	} else {
//		for (int i = currentResult[current - 1] + 1; i < target; i++) {
//			if (!flags[i]) {   // pruning.
//				continue;
//			}
//			currentResult[current] = i;
//			if (GetMinResult(currentResult, current + 1, target, minLength, minResult)) {
//				break;        // pruning.
//			}
//		}
//		return false;
//	}
//}

// iterative deepening search.
bool GetMinResultIDS (vector<int>& currentResult, int current, int depth, int target, vector<int>& minResult) {
	vector<bool> flags(10002, false);
	for (int i = 0; i < current; i++) {
		flags[currentResult[i]] = true;
		for (int j = i; j < current; j++) {
			if (currentResult[j] + currentResult[i] <= target) {
				flags[currentResult[j] + currentResult[i]] = true;
			}
		}
	}

	if (current == depth) {
		if (flags[target]) {
			minResult = currentResult;
			return true;  
		} else {
			return false;
		}
	} else {
		for (int i = currentResult[current - 1] + 1; i < target; i++) {
			if (!flags[i]) {   // pruning.
				continue;
			}
			if (i * pow(2, depth - current) < target) {  // pruning: if the max is still smaller than target, skip.
				continue;
			}
			currentResult[current] = i;
			if (GetMinResultIDS(currentResult, current + 1, depth, target, minResult)) {
				return true;
			}
		}
		return false;
	}
}

int main () {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		vector<int> minResult(10002);
		vector<int> currentResult(10002);
		currentResult[0] = 1;
		if (n == 1) {
			cout << "1" << endl;
		} else {
			int minDepth = 0;
			int tempNum = 1;
			while (tempNum < n) {
				minDepth++;
				tempNum *= 2;
			}
			while (!GetMinResultIDS(currentResult, 1, minDepth, n, minResult)) {
				minDepth++;
			}
			for (int i = 0; i < minDepth; i++) {
				cout << minResult[i] << " ";
			}
			cout << n << endl;
		}
	}
}

// NEED REVIEW!!!
// 1. Notice the 3 pruning points in the algorithm, the first
//    one is of vital importance.
// 2. Study the "Iterative Deepen Algorithm". It can make the 
//    algorithm better.
// 3. Summarize the searching approaches.
// 4. TLE for current algorithm, the test machine for UVA is 
//    really bad, then try the following offline version.
// 5. However the scale of data is different between online
//    version and PDF version. Need to user advanced technic.


//#include <iostream>
//#include <vector>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//
//string result[101] = {
//	"",
//	"1",
//	"1 2",
//	"1 2 3",
//	"1 2 4",
//	"1 2 3 5",
//	"1 2 3 6",
//	"1 2 3 4 7",
//	"1 2 4 8",
//	"1 2 3 6 9",
//	"1 2 3 5 10",
//	"1 2 3 4 7 11",
//	"1 2 3 6 12",
//	"1 2 3 5 8 13",
//	"1 2 3 4 7 14",
//	"1 2 3 5 10 15",
//	"1 2 4 8 16",
//	"1 2 4 8 9 17",
//	"1 2 3 6 9 18",
//	"1 2 3 4 8 11 19",
//	"1 2 3 5 10 20",
//	"1 2 3 4 7 14 21",
//	"1 2 3 4 7 11 22",
//	"1 2 3 5 10 13 23",
//	"1 2 3 6 12 24",
//	"1 2 3 5 10 15 25",
//	"1 2 3 5 8 13 26",
//	"1 2 3 6 9 18 27",
//	"1 2 3 4 7 14 28",
//	"1 2 3 4 7 11 18 29",
//	"1 2 3 5 10 15 30",
//	"1 2 3 4 7 14 17 31",
//	"1 2 4 8 16 32",
//	"1 2 4 8 16 17 33",
//	"1 2 4 8 9 17 34",
//	"1 2 3 4 7 14 21 35",
//	"1 2 3 6 9 18 36",
//	"1 2 3 5 8 16 21 37",
//	"1 2 3 4 8 11 19 38",
//	"1 2 3 5 8 13 26 39",
//	"1 2 3 5 10 20 40",
//	"1 2 3 5 10 20 21 41",
//	"1 2 3 4 7 14 21 42",
//	"1 2 3 5 10 20 23 43",
//	"1 2 3 4 7 11 22 44",
//	"1 2 3 5 10 15 30 45",
//	"1 2 3 5 10 13 23 46",
//	"1 2 3 4 7 10 20 27 47",
//	"1 2 3 6 12 24 48",
//	"1 2 3 6 12 24 25 49",
//	"1 2 3 5 10 15 25 50",
//	"1 2 3 6 12 24 27 51",
//	"1 2 3 5 8 13 26 52",
//	"1 2 3 5 6 12 24 29 53",
//	"1 2 3 6 9 18 27 54",
//	"1 2 3 4 7 11 22 33 55",
//	"1 2 3 4 7 14 28 56",
//	"1 2 3 4 7 14 28 29 57",
//	"1 2 3 4 7 11 18 29 58",
//	"1 2 3 4 7 14 28 31 59",
//	"1 2 3 5 10 15 30 60",
//	"1 2 3 5 7 14 28 33 61",
//	"1 2 3 4 7 14 17 31 62",
//	"1 2 3 4 7 14 21 42 63",
//	"1 2 4 8 16 32 64",
//	"1 2 4 8 16 32 33 65",
//	"1 2 4 8 16 17 33 66",
//	"1 2 3 4 8 16 32 35 67",
//	"1 2 4 8 9 17 34 68",
//	"1 2 3 5 8 16 32 37 69",
//	"1 2 3 4 7 14 21 35 70",
//	"1 2 3 4 7 8 16 32 39 71",
//	"1 2 3 6 9 18 36 72",
//	"1 2 3 6 9 18 36 37 73",
//	"1 2 3 5 8 16 21 37 74",
//	"1 2 3 5 10 15 25 50 75",
//	"1 2 3 4 8 11 19 38 76",
//	"1 2 4 5 9 18 36 41 77",
//	"1 2 3 5 8 13 26 39 78",
//	"1 2 3 4 7 9 18 36 43 79",
//	"1 2 3 5 10 20 40 80",
//	"1 2 3 5 10 20 40 41 81",
//	"1 2 3 5 10 20 21 41 82",
//	"1 2 3 5 10 20 40 43 83",
//	"1 2 3 4 7 14 21 42 84",
//	"1 2 3 5 10 20 40 45 85",
//	"1 2 3 5 10 20 23 43 86",
//	"1 2 3 4 7 10 20 40 47 87",
//	"1 2 3 4 7 11 22 44 88",
//	"1 2 3 4 7 11 22 44 45 89",
//	"1 2 3 5 10 15 30 45 90",
//	"1 2 3 4 7 11 22 44 47 91",
//	"1 2 3 5 10 13 23 46 92",
//	"1 2 3 4 7 14 17 31 62 93",
//	"1 2 3 4 7 10 20 27 47 94",
//	"1 2 3 4 7 11 22 44 51 95",
//	"1 2 3 6 12 24 48 96",
//	"1 2 3 6 12 24 48 49 97",
//	"1 2 3 6 12 24 25 49 98",
//	"1 2 3 6 12 24 48 51 99",
//	"1 2 3 5 10 15 25 50 100"
//};
//
//int main () {
//	while (true) {
//		int n;
//		cin >> n;
//		if (n == 0) {
//			break;
//		}
//		cout << result[n] << endl;
//	}
//}

//bool GetMinResult (vector<int>& currentResult, int current, int target, int& minLength, vector<int>& minResult) {
//	if (current > minLength) {
//		return false;     // key pruning point.
//	}
//
//	vector<bool> flags(102, false);
//	for (int i = 0; i < current; i++) {
//		flags[currentResult[i]] = true;
//		for (int j = i; j < current; j++) {
//			if (currentResult[j] + currentResult[i] <= target) {
//				flags[currentResult[j] + currentResult[i]] = true;
//			}
//		}
//	}
//
//	if (flags[target]) {
//		if (current < minLength) {
//			minLength = current;
//			minResult = currentResult;
//		}
//		return true;
//	} else {
//		for (int i = currentResult[current - 1] + 1; i < target; i++) {
//			if (!flags[i]) {   // pruning.
//				continue;
//			}
//			currentResult[current] = i;
//			if (GetMinResult(currentResult, current + 1, target, minLength, minResult)) {
//				break;        // pruning.
//			}
//		}
//		return false;
//	}
//}
//
//int main () {
//	ofstream outfile("out.txt");
//	streambuf *streams=cout.rdbuf();
//	cout.rdbuf(outfile.rdbuf());
//	for (int n = 1; n <= 100; n++) {
//		int minLength = 200;
//		vector<int> minResult(100);
//		vector<int> currentResult(100);
//		currentResult[0] = 1;
//		if (n == 1) {
//			cout << "1" << endl;
//		} else {
//			GetMinResult(currentResult, 1, n, minLength, minResult);
//			cout << "\"";
//			for (int i = 0; i < minLength; i++) {
//				cout << minResult[i] << " ";
//			}
//			cout << n << "\"," << endl;
//		}
//	}
//	cout.rdbuf(streams);
//}

