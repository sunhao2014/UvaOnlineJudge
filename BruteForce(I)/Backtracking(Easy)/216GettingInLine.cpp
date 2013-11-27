#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

class Point {
public:
	int m_x;
	int m_y;
	Point(){}
	Point(int x, int y) {
		m_x = x;
		m_y = y;
	}
};

void GetMinLength (vector<int>& permutationResult, vector<int>& minPermutation, vector<Point>& data, int n, int currentIndex, double& minLength) {
	if (n == currentIndex) {
		double sumLength = 0;
		for (int i = 1; i <= n - 1; i++) {
			int x1, y1, x2, y2;
			x1 = data[permutationResult[i - 1]].m_x;
			y1 = data[permutationResult[i - 1]].m_y;
			x2 = data[permutationResult[i]].m_x;
			y2 = data[permutationResult[i]].m_y;
			double temp = ((int)(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) * 100 + 0.5)) / 100.0;
			sumLength += temp;
		}
		if (sumLength < minLength) {
			minLength = sumLength;
			//cout << minLength << endl;
			minPermutation = permutationResult;
		}
	} else {
		for (int i = 0; i < n; i++) {
			bool isOccured = false;
			for (int j = 0; j < currentIndex; j++) {
				if (permutationResult[j] == i) {
					isOccured = true;
					break;
				}
			}
			if (!isOccured) {
				permutationResult[currentIndex] = i;
				GetMinLength(permutationResult, minPermutation, data, n, currentIndex + 1, minLength);
			}
		}
	}
}

int main() {
	int count = 1;
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		vector<Point> data(n);
		for (int i = 0; i < n; i++) {
			cin >> data[i].m_x >> data[i].m_y;
		}
		vector<int> permutationResult(n);
		vector<int> minPermutation(n);
		double minLength = 9999999999;
		GetMinLength(permutationResult, minPermutation, data, n, 0, minLength);
		cout << "**********************************************************" << endl;
		cout << "Network #" << count++ << endl;
		double sumLength = 0;
		for (int i = 1; i <= n - 1; i++) {
			int x1, y1, x2, y2;
			x1 = data[minPermutation[i - 1]].m_x;
			y1 = data[minPermutation[i - 1]].m_y;
			x2 = data[minPermutation[i]].m_x;
			y2 = data[minPermutation[i]].m_y;
			double temp = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) + 16;
			sumLength += temp;
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", x1, y1, x2, y2, temp);
		}
		printf("Number of feet of cable required is %.2lf.\n", sumLength);
	}
}

//
// 1. Review: the min and max number of int and double, etc.
// 2. How to keep two decimal places.
// 3. Notice the first point won't always be the first point, thanks to
//    this misunderstanding, I have gotten 3 WAs.
// 4. Find a potential bug by print the minLength. Notice we should use
//    the "pass by reference" here, the function of this method is equal
//    to the global variable.
// 