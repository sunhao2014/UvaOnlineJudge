#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector<int> maxResult(10, 0);
int maxCurrencyValue;
int m, n;

void GetCurrentCurrencyValue(vector<int>& tempResult, vector<int>& currentResult, int current, int currentN, vector<int>& flags) {
	if (current == m) {
		return;
	} else {
		for (int i = 0; i < currentN; i++) {
			tempResult[current] = currentResult[i];
			int temp = 0;
			for (int i = 0; i < current + 1; i++) {
				temp += tempResult[i];
			}
			flags[temp] = 1;
			GetCurrentCurrencyValue(tempResult, currentResult, current + 1, currentN, flags);
		}
	}
}

void GetMaxCurrencyValue(vector<int>& currentResult, int current, int start, int end) {
	if (current == n)
		return;
	for (int i = start; i <= end; i++) {
		currentResult[current] = i;
		vector<int> tempResult(m);
		int currentCurrencyValue;
		vector<int> flags(1000, 0);
		GetCurrentCurrencyValue(tempResult, currentResult, 0, current + 1, flags);
		for (currentCurrencyValue = 1; currentCurrencyValue < 1000; currentCurrencyValue++) {
			if (!flags[currentCurrencyValue]) {
				break;
			}
		}
		currentCurrencyValue--;
		if (currentCurrencyValue > maxCurrencyValue) {
			maxCurrencyValue = currentCurrencyValue;
			maxResult = currentResult;
		}
		GetMaxCurrencyValue(currentResult, current + 1, i + 1, currentCurrencyValue + 1);
	}
}

int main() {
	while (true) {
		maxCurrencyValue = 0;
		maxResult.resize(10);
		cin >> m >> n;
		if (m == 0 && n == 0) {
			break;
		}
		vector<int> currentResult(n);
		currentResult[0] = 1;
		// NOTICE: There are two edge cases.
		if (m == 1) {       // only one stamp.
			maxCurrencyValue = n;
			for (int i = 0; i < n; i++) {
				maxResult[i] = i + 1;
			}
		} else if (n == 1){
			maxCurrencyValue = m;
			maxResult[0] = 1;
		} else {
			GetMaxCurrencyValue(currentResult, 1, 2, m + 1);
		}
		for (int i = 0; i < n; i++) {
			printf("%3d", maxResult[i]);
		}
		printf(" ->%3d\n", maxCurrencyValue);
	}
}

// STRONGLY NEEDS REVIEW.
// This a really bad experience, I spent 5 hours on this problem.
// At first don't know how to launch the enumeration, then noticed
// the next element's range can be determined by the previous one.
// However I still spent a lot of time for implementation. Should
// get clear before begin to write code, otherwise it will waste a
// lot of time debugging and altering the algorithm. All in all, it
// is a failure example for this problem, and must have lessons by
// spending so much time on it.
// 1. Later the final result should use global variable to make the
//    function clear. Notice we need to reset the variable in main
//    function.
// 2. There are two nested recursion in this problem, which make the
//    code a little bit complicated. Make sure the logic is clear
//    before writing the code.
// 3. Analyze time complicity of this problem.
//