#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

struct Data {
	int m_x;
	int m_y;
	int m_count;
};

int main() {
	int matrixNum;
	cin >> matrixNum;
	vector<Data> data(27);
	for (int i = 0; i < matrixNum; i++) {
		char name;
		cin >> name;
		int x, y;
		cin >> x >> y;
		data[name - 'A'].m_x = x;
		data[name - 'A'].m_y = y;
		data[name - 'A'].m_count = 0;
	}
	string query;
	while (cin >> query) {
		int length = query.length();
		stack<Data> resultStack;
		bool isValid = true;
		for (int i = 0; i < length; i++) {
			if (query[i] != '(' && query[i] != ')') {
				resultStack.push(data[query[i] - 'A']);
			} else if (query[i] == ')') {
				Data rightElement, leftElement;
				rightElement = resultStack.top();
				resultStack.pop();
				leftElement = resultStack.top();
				resultStack.pop();
				if (leftElement.m_y != rightElement.m_x) {
					isValid = false;
					cout << "error" << endl;
					break;
				} else {
					leftElement.m_count += leftElement.m_x * leftElement.m_y * rightElement.m_y + rightElement.m_count;  // forgot the last element at the first time.
					leftElement.m_y = rightElement.m_y; 
					resultStack.push(leftElement);
				}
			}
		}
		if (isValid) {
			// reverse the stack.
			stack<Data> resultStackReverse;
			while (!resultStack.empty()) {
				Data temp = resultStack.top();
				resultStack.pop();
				resultStackReverse.push(temp);
			}
			while (resultStack.size() > 1) {
				Data firstElement, secondElement;
				firstElement = resultStackReverse.top();
				resultStackReverse.pop();
				secondElement = resultStackReverse.top();
				resultStackReverse.pop();
				firstElement.m_count += firstElement.m_x + firstElement.m_y + secondElement.m_y + secondElement.m_count;  // forgot the last element at the first time.
				firstElement.m_y = secondElement.m_y;
				resultStackReverse.push(firstElement);
			}
			Data lastElement = resultStackReverse.top();
			cout << lastElement.m_count << endl;
		}
	}
}