#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int n;
int data[1000];
bool visitd[1000];
int answer;

int compare (const int& a, const int& b) {
	return a > b;
}

bool IsValidAnswer (int current, int currentSum, int activeCount) {
	if (activeCount == 0) {    // if all elements have been deleted.
		return true;
	}
	for (int i = current; i < n; i++) {
		if (visitd[i]) {
			continue;
		}
		if (currentSum + data[i] < answer) {
			visitd[i] = true;
			// Notice the first parameter, it should be "i" but not "current",
			// thanks to this bug, I've spent 1 hour time and 
			if (IsValidAnswer(i + 1, currentSum + data[i], activeCount - 1)) {  
				return true;
			} else {
				visitd[i] = false;
				int temp = data[i];
				while (i < n && data[i] == temp) {  // pruning.
					i++;
				}
				//continue;
			}
		} else if (currentSum + data[i] == answer) {
			visitd[i] = true;
			if (IsValidAnswer(0, 0, activeCount - 1)) {
				return true;
			} else {
				visitd[i] = false; // Don't forget this.
				return false; // Notice this pruning, perfect!!!
			}
		}

		// Pruning: if current value is larger than the headroom, 
		// then doesn't need to go deeper. There is no solution
		// for this branch.
		if (currentSum == 0) {
			return false;
		}
	}
	return false;
}

int main() {
	while (true) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		memset(data, 0, sizeof(data));
		int sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &data[i]);
			visitd[i] = false;
			sum += data[i];
		}
		sort(data, data + n, compare);
		for (int i = 1; i <= sum; i++) {
			memset(visitd, 0, sizeof(visitd));
			if (sum % i == 0 && i >= data[0]) {
				answer = i;
				if (IsValidAnswer(0, 0, n)) {
					printf("%d\n", answer);
					break;  // this is of vital importance.
				}
			}
		} 
	}
}

// BLOCKED AT PHASE 1!!! CLASSIC PROBLEM FOR PRUNING, STRONGLY NEEDS REVIEW.
// 1. Notice the the DFS method for judging whether it is a 
//    valid answer. This is the key point.
// 2. Notice the two pruning process, see inline.
// 3. Analyze the time complicity for the algorithm.
// 4. Compare this algorithm with enumerate the subset of every
//    element, which one is better?
// 5. Notice the usage of sort.
// 6. Review the subset sum problem.
//