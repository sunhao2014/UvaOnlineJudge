#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <cmath>

using namespace std;
char leftNumber[1000];
int leftCount;
char rightNumber[1000];
int rightCount;
char resultNumber[1000];
int resultCount;
map<char, int> romanMap;
map<char, int> romanToArabic;

bool IsRomanCorrect() {
	int leftInt = 0;
	for (int i = 0; i < leftCount - 1; i++) {
		// Note that this should be ">=".
		if (romanMap[leftNumber[i]] >= romanMap[leftNumber[i + 1]]) {
			leftInt += romanMap[leftNumber[i]];
		} else {
			leftInt -= romanMap[leftNumber[i]];
		}
	}
	leftInt += romanMap[leftNumber[leftCount - 1]];

	int rightInt = 0;
	for (int i = 0; i < rightCount - 1; i++) {
		if (romanMap[rightNumber[i]] >= romanMap[rightNumber[i + 1]]) {
			rightInt += romanMap[rightNumber[i]];
		} else {
			rightInt -= romanMap[rightNumber[i]];
		}
	}
	rightInt += romanMap[rightNumber[rightCount - 1]];

	int resultInt = 0;
	for (int i = 0; i < resultCount - 1; i++) {
		if (romanMap[resultNumber[i]] >= romanMap[resultNumber[i + 1]]) {
			resultInt += romanMap[resultNumber[i]];
		} else {
			resultInt -= romanMap[resultNumber[i]];
		}
	}
	resultInt += romanMap[resultNumber[resultCount - 1]];

	if (leftInt + rightInt == resultInt) {
		return true;
	} else {
		return false;
	}
}

int GetArabicStatus(vector<int>& currentResult, int current, int n, int& status) {
	if (current == n) {
		map<char, int>::iterator iter;
		int cur = 0;
		for (iter = romanToArabic.begin(); iter != romanToArabic.end(); ++iter) {
			iter->second = currentResult[cur++];
		}
		if (romanToArabic[leftNumber[0]] == 0 ||
			romanToArabic[rightNumber[0]] == 0 ||
			romanToArabic[resultNumber[0]] == 0 ) {
				return status;
		}
		int leftInt = 0;
		for (int i = 0; i < leftCount; i++) {
			leftInt += romanToArabic[leftNumber[i]] * pow(10, leftCount - 1 - i);
		}
		int rightInt = 0;
		for (int i = 0; i < rightCount; i++) {
			rightInt += romanToArabic[rightNumber[i]] * pow(10, rightCount - 1 - i);
		}
		int resultInt = 0;
		for (int i = 0; i < resultCount; i++) {
			resultInt += romanToArabic[resultNumber[i]] * pow(10, resultCount - 1 - i);
		}
		if (leftInt + rightInt == resultInt) {
			if (status == 2) {
				status = 3;
			} else if (status == 3) {
				status = 1;
			}
		}
		return status;
	} else {
		for (int i = 0; i < 10; i++) {
			bool isExist = false;
			for (int j = 0; j < current; j++) {
				if (currentResult[j] == i) {
					isExist = true;
					break;
				}
			}
			if (isExist) {
				continue;
			}
			currentResult[current] = i;
			if (GetArabicStatus(currentResult, current + 1, n, status) == 1) {
				return 1;   // pruning.
			}
		}
		return status;   // Notice this point, have the similar error before.
	}
}

void CheckArabic() {
	int n = romanToArabic.size();
	vector<int> currentResult(10);
	int status = 2; // impossible in initial.
	switch (GetArabicStatus(currentResult, 0, n, status)) {
	case 1:
		printf("ambiguous\n");
		break;
	case 2:
		printf("impossible\n");
		break;
	case 3:
		printf("valid\n");
		break;
	default:
		break;
	}
}

int main() {
	romanMap['I'] = 1;
	romanMap['V'] = 5;
	romanMap['X'] = 10;
	romanMap['L'] = 50;
	romanMap['C'] = 100;
	romanMap['D'] = 500;
	romanMap['M'] = 1000;
	while (true) {
		memset(leftNumber, 0, sizeof(leftNumber));
		memset(rightNumber, 0, sizeof(rightNumber));
		memset(resultNumber, 0, sizeof(resultNumber));
		romanToArabic.clear();
		leftCount = 0;
		rightCount = 0;
		resultCount = 0;
		char currentChar;
		currentChar = getchar();
		if (currentChar == '#') {
			break;
		}
		int currentPos = 0;
		while (currentChar != '+') {
			leftNumber[currentPos++] = currentChar;
			romanToArabic[currentChar] = 0;
			leftCount++;
			currentChar = getchar();
		}
		currentPos = 0;
		currentChar = getchar();
		while (currentChar != '=') {
			rightNumber[currentPos++] = currentChar;
			romanToArabic[currentChar] = 0;
			rightCount++;
			currentChar = getchar();
		}
		currentPos = 0;
		currentChar = getchar();
		while (currentChar != '\n') {
			resultNumber[currentPos++] = currentChar;
			romanToArabic[currentChar] = 0;
			resultCount++;
			currentChar = getchar();
		}
		if (IsRomanCorrect()) {
			printf("Correct ");
			CheckArabic();
		} else {
			printf("Incorrect ");
			CheckArabic();
		}
	}
}