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
			bool isExistInResult = false;
			for (int j = 0; j < currentPos; j++) {
				if (result[j] == i) {
					isExistInResult = true;
					break;
				}
			}
			if (!isExistInResult) {
				result[currentPos] = i;
				GeneratePermutation(result, size, currentPos + 1);
			}
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
1. We can improve the algorithm in GeneratePermutationVector1, that we doesn't
   need a vector that contains the current unselected set. What should do is only
   keep the result vector and enumerate the current number from 1 to n, if it exists
   in current result, then skip it, otherwise put the number in current position,
   then get a sub-problem.
2. If the number is extremely large, the program will cost a lot of memory, investigate
   the memory usage and draw a precise conclusion.
*/