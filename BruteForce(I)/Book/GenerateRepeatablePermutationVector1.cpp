#include <iostream>
#include <vector>

using namespace std;

void GeneratePermutation (vector<int> result, int size, int currentPos) {
	if (currentPos == size) {
		for (int i = 0; i < size; i++) {
			cout << result[i] << " ";
		}
		cout << endl;
	} else {
		for (int i = 1; i <= size; i++) {
			result[currentPos] = i;
			GeneratePermutation(result, size, currentPos + 1);
		}
	}
}

int main() {
	int num;
	cin >> num;
	vector<int> result(num);
	GeneratePermutation(result, num, 0);
	return 0;
}

/*
1. This problem is easy to solve. But notice the difference between this one
   and the next one(see GeneratePermutationFromGivenVector1).
*/