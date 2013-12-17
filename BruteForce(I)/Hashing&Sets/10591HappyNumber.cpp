#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int numOfCases;
	cin >> numOfCases;
	int count = 1;
	while (numOfCases--) {
		int previousNumber;
		cin >> previousNumber;
		int temp = previousNumber;
		map<int, int> hashMap;
		hashMap[previousNumber] = 1;
		while (true) {
			int currentNumber = 0;
			while (temp != 0) {
				currentNumber += (temp % 10) * (temp % 10);
				temp /= 10;
			}
			if (currentNumber == 1) {
				cout << "Case #" << count++ << ": " << previousNumber << " is a Happy number." << endl;
				break;
			}
			if (hashMap.count(currentNumber) != 0) {
				cout << "Case #" << count++ << ": " << previousNumber << " is an Unhappy number." << endl;
				break;
			}
			hashMap[currentNumber] = 1;
			temp = currentNumber;
		}
	}
}