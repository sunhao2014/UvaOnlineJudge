#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int numOfCases;
	cin >> numOfCases;
	for (int p = 0; p < numOfCases; p++) {
		int n;
		cin >> n;
		vector<double> data;
		double sumMin = 0;
		for (int i = 0; i < n; i++) {
			double curr;
			cin >> curr;
			sumMin += 2 * curr; 
			data.push_back(curr);
		}
		sort(data.begin(), data.end());

		do {
			// for each circle, we calculate its center distance with all
			// previous circles, the largest one plus the center is the
			// current center. IMPROTANT!
			double sum = 0;
			vector<double> centers(n);
			centers[0] = data[0];
			for (int i = 1; i < n; i++) {
				double maxCenter = 0;
				for (int j = 0; j < i; j++) {
					double currentCenter = centers[j] + sqrt((data[i] + data[j]) * (data[i] + data[j]) - (data[i] - data[j]) * (data[i] - data[j]));
					if (currentCenter > maxCenter) {
						maxCenter = currentCenter;
					}
				}
				centers[i] = maxCenter;
			}

			// we use "left" to adjust the origin, in the aforementioned
			// code the origin is equal to the left edge of the first circle,
			// however in some cases it is improper, think of the case the 
			// first circle is very small.
			// then use the "right" to get the the right edge of the box, 
			// and this is easy to understand.
			double left = 0;      
			double right = 0;
			for (int i = 0; i < n; i++) {
				double currentLeft = data[i] - centers[i];
				double currentRight = data[i] + centers[i];
				if (currentLeft > left) {
					left = currentLeft;
				}
				if (currentRight > right) {
					right = currentRight;
				}
			}
			sum = right + left;
			if (sum < sumMin) {
				sumMin = sum;
			}
		} while (next_permutation(data.begin(), data.end()));
		printf("%.3lf\n", sumMin);
	}
}

//
// 1. Notice there is a trick in the problem. Think of a case which
//    the previous circle has very large radius but the following has
//    a very small radius. How to solve this case? Look at the code for
//    solution.
//