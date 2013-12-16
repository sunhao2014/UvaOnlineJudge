#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main () {
	map<string, int> dict;
	string word;
	while (cin >> word) {
		dict[word] = 1;
	}

	map<string, int>::iterator iter;
	for (iter = dict.begin(); iter != dict.end(); ++iter) {
		string thisWord = iter->first;
		int n = thisWord.length();
		for (int i = 1; i < n; i++) {
			string firstSubstring = thisWord.substr(0, i);
			string secondSubstring = thisWord.substr(i, n - i);
			if (dict.count(firstSubstring) != 0 && dict.count(secondSubstring) != 0) {
				cout << thisWord << endl;
				break;
			}
		}
	}
}