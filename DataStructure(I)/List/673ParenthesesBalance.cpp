#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <stack>

using namespace std;

int main() {
	int numOfCases;
	cin >> numOfCases;
	getchar();
	while (numOfCases--) {
		string data;
		getline(cin, data);
		int length = data.length();
		int parenthesesCount = 0;
		int squareBracketCount = 0;
		stack<char> tempStack;
		bool isValid = true;
		for (int i = 0; i < length; i++) {
			if (data[i] == '(') {
				tempStack.push(data[i]);
			} else if (data[i] == '[') {
				tempStack.push(data[i]);
			} else if (data[i] == ')') {
				if (tempStack.empty()) {
					cout << "No" << endl;
					isValid = false;
					break;
				}
				char tempChar = tempStack.top();
				tempStack.pop();
				if (tempChar != '(') {
					cout << "No" << endl;
					isValid = false;
					break;
				}
			} else if (data[i] == ']') {
				if (tempStack.empty()) {
					cout << "No" << endl;
					isValid = false;
					break;
				}
				char tempChar = tempStack.top();
				tempStack.pop();
				if (tempChar != '[') {
					cout << "No" << endl;
					isValid = false;
					break;
				}
			}
		}
		if (isValid) {
			if (tempStack.empty()) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		}
	}
}

//
// 1. Notice the following cases:
//    1) "((("
//    2) ""
//    3) "([)]"   -- this means must use a stack.
//
