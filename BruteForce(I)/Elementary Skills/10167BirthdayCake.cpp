#include <iostream>
#include <vector>
using namespace std;

struct Point {
	int m_x;
	int m_y;
};

int main() {
	int n;
	while (true) {
r1:		cin >> n;
		if (n == 0)
			break;
		vector<Point> data(2 * n);
		for (int i = 0; i < 2 * n; i++) {
			cin >> data[i].m_x;
			cin >> data[i].m_y;
		}
		for (int a = -500; a <= 500; a++) {
			for (int b = -500; b <= 500; b++) {
				int upCount = 0;
				int downCount = 0;
				bool needSkip = false;  // if there is one cherry on the line, then should skip.
				if (b == 0) {
					for (int i = 0; i < 2 * n; i++) {
						if (data[i].m_x > 0) {
							upCount++;
						} else if (data[i].m_x < 0) {
							downCount++;
						} else {
							needSkip = true;
						}
					}
				} else {
					double k = -a / (double)b;
					for (int i = 0; i < 2 * n; i++) {
						if (k * data[i].m_x > data[i].m_y) {
							upCount++;
						} else if (k * data[i].m_x < data[i].m_y) {
							downCount++;
						} else {
							needSkip = true;
						}
					}
				}
				if (!needSkip && upCount == downCount) {
					cout << a << " " << b << endl;
					goto r1;
				}
			}
		}
	}
}

/*
1. A strange problem, there are many answers to an input. Seems cannot get
   anything from this problem. Just notice the boundaries.
*/