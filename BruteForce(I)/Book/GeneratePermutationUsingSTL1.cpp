#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
	int num;
	cin >> num;
	vector<int> data(num);
	for (int i = 0; i < num; i++) {
		cin >> data[i];
	}
	sort(data.begin(), data.end());
	do {
		for (int i = 0; i < num; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	} while (next_permutation(data.begin(), data.end()));
}

/*
1. Review the usage of next_permutation.(doc & http://leonard1853.iteye.com/blog/1450085)
2. Have a look at the snail sort in STL doc.
3. Notice the usage of "do".
4. Dive into next_permutation function to study the background algorithm. 
*/