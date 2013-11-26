#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main () {
	int numOfCases;
	cin >> numOfCases;
	for (int i = 0; i < numOfCases; i++) {
		int n, h;
		cin >> n >> h;
		string data(n, '0');
		for (int i = 0; i < h; i++) {
			data[n - 1 - i] = '1';
		}
		do {
			cout << data << endl;
		} while (next_permutation(data.begin(), data.end()));
		// "Print a blank line between datasets"
		// this means doesn't need a blank line after the 
		// last case. This is really BORING!!!
		if (i != numOfCases - 1) {
			cout << endl;
		}
	}
}

/*
1. The same as "GeneratePermutationUsingSTL1".
*/