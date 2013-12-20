#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

int main() {
	int numOfCases;
	cin >> numOfCases;
	while (numOfCases--) {
		int n;
		cin >> n;
		getchar();    // if we use get line, we have to use this function to filter the "\n".
		vector<string> origin(n);
		vector<string> result(n);
		for (int i = 0; i < n; i++) {
			getline(cin, origin[i]);
		}
		for (int i = 0; i < n; i++) {
			getline(cin, result[i]);
		}
		int originPtr = n - 1;
		int resultPtr = n - 1;
		while (originPtr >= 0) {
			if (origin[originPtr] == result[resultPtr]) {
				originPtr--;
				resultPtr--;
				continue;
			}
			while ( originPtr >= 0 && origin[originPtr] != result[resultPtr]) {  // notice the order.
				originPtr--;
			}
			if (originPtr >= 0) {
				originPtr--;
				resultPtr--;
			}
		}
		for (int i = resultPtr; i >= 0; i--) {
			cout << result[i] << endl;
		}
		cout << endl;
	}
}