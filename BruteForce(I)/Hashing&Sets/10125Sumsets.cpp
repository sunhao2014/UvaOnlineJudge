#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct DataPair {
	int m_i;
	int m_j;
};

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		vector<int> data(n);
		for (int i = 0; i < n; i++) {
			cin >> data[i];
		}
		
		// note that we need to find the largest d!
		sort(data.begin(), data.end());

		multimap<int, DataPair> hashMap;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				DataPair temp;
				temp.m_i = i;
				temp.m_j = j;
				hashMap.insert(make_pair(data[i] + data[j], temp));
			}
		}
		bool haveSolution = false;
		for (int i = n - 1; i >= 0 && !haveSolution; i--) {
			for (int j = 0; j < n && !haveSolution; j++) {
				if (i != j) {
					typedef multimap <int, DataPair>::const_iterator CIT;
					typedef pair<CIT, CIT> Range;
					Range range = hashMap.equal_range(data[i] - data[j]);
					for(CIT iter = range.first; iter != range.second; ++iter) {
						int currentI = iter->second.m_i;
						int currentJ = iter->second.m_j;
						if (i != currentI && i != currentJ && j != currentI && j != currentJ) {
							cout << data[i] << endl;
							haveSolution = true;
							break;
						}
					}
				}
			}
		}
		if (!haveSolution) {
			cout << "no solution" << endl;
		}
	}
}