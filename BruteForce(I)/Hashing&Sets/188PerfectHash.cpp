#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int main() {
	string data;
	while (getline(cin, data)) {
		stringstream ss;
		ss << data;
		vector<string> words;
		string temp;
		while (ss >> temp) {
			words.push_back(temp);
		}
		vector<int> wordCodes;
		vector<string>::iterator iter;
		int maxCode = 0;
		int secondMaxCode = 0;
		for (iter = words.begin(); iter != words.end(); ++iter) {
			string thisWord = *iter;
			int n = iter->size();
			int code = 0;
			for (int i = 1; i <= n; i++) {
				int temp = thisWord[n - i] - 'a' + 1;
				code += (temp << 5 * (i - 1));
			}
			if (code > maxCode) {
				secondMaxCode = maxCode;
				maxCode = code;
			} else if (code > secondMaxCode) {
				secondMaxCode = code;
			}
			wordCodes.push_back(code);
		}

		int c = secondMaxCode;
		bool hasNoConflict = false;
		while (!hasNoConflict) {
			hasNoConflict = true;
			map<int, int> hashMap;
			vector<int>::iterator iter;
			int n = wordCodes.size();
			for (iter = wordCodes.begin(); iter != wordCodes.end(); ++iter) {
				int hashCode = (c / (*iter)) % n;
				if (hashMap.count(hashCode) == 0) { // no conflict of this element
					hashMap[hashCode] = *iter;
				} else {
					hasNoConflict = false;
					int wi = hashMap[hashCode];
					int wj = *iter;
					if ((c / wi + 1) * wi < (c / wj + 1) * wj) {
						c = (c / wi + 1) * wi;
					} else {
						c = (c / wj + 1) * wj;
					}
					break;
				}
			}
		}
		cout << data << endl;
		cout << c << endl << endl;
	}
}