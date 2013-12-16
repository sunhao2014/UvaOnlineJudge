#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main() {
	char endChar = getchar();
	map<string, string> dict;
	while (endChar != '\n') {
		string key, value;
		string temp;
		cin >> temp;
		value = endChar + temp;
		cin >> key;
		dict[key] = value;
		getchar();
		endChar = getchar();
	}

	string query;
	while (cin >> query) {
		if (dict.count(query) == 0) {
			cout << "eh" << endl;
		} else {
			cout << dict[query] << endl;
		}
	}
}

//
// 1. Review the string hash algorithm.
//