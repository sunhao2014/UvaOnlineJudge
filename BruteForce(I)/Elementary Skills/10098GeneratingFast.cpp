#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main () {
	int numOfCases;
	cin >> numOfCases;
	for (int i = 0; i < numOfCases; i++) {
		string data;
		cin >> data;
		sort(data.begin(), data.end());
		do {
			cout << data << endl;
		} while (next_permutation(data.begin(), data.end()));
		cout << endl;
	}
}

/*
1. The same as "GeneratePermutationUsingSTL1".
*/