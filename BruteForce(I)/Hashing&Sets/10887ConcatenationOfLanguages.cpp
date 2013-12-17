#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int main () {
	int numOfCases;
	cin >> numOfCases;
	int count = 1;
	while (numOfCases--) {
		int n, m;
		cin >> n >> m;
		vector<string> langA(n);
		vector<string> langB(m);
		getchar();
		for (int i = 0; i < n; i++) {
			// the input can be "", thus notice we need to use getline,
			// and the previous getchar() is used to skip the "\n".
			getline(cin, langA[i]) ;
		}
		for (int i = 0; i < m; i++) {
			getline(cin, langB[i]) ;
		}
		cout << "Case " << count++ << ": "; 
		map<string, int> hashMap;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				string temp = langA[i] + langB[j];
				if (hashMap.count(temp) == 0) {
					hashMap[temp] = 1;
				}
			}
		}
		cout << hashMap.size() << endl;
	}
}

//
// 1. Inline.
// 2. Review string hash algorithm.
//