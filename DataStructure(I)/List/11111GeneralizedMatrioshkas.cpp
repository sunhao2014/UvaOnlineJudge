#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <list>

using namespace std;

struct Data {
	int m_data;
	int m_position;
};

struct ListNode {
	int m_total;
	int m_start;
	int m_end;
};

int main () {
	string input;
	while (getline(cin, input)) {
		stringstream sstream;
		sstream << input;
		int currentNum;
		stack<Data> dataStack;
		list<ListNode> flagList;
		int currentPosition = 0;
		bool isValid = true;
		while (sstream >> currentNum) {
			Data currentNode;
			currentNode.m_data = currentNum;
			currentNode.m_position = currentPosition++;
			if (currentNum < 0) {
				dataStack.push(currentNode);
			} else {
				if (dataStack.empty()) {
					isValid = false;
					break;
				}
				if (dataStack.top().m_data != -currentNum) {
					isValid = false;
					break;
				}
				Data startNode = dataStack.top();
				dataStack.pop();
				ListNode currentListNode;
				currentListNode.m_start = startNode.m_position;
				currentListNode.m_end = currentNode.m_position;
				currentListNode.m_total = currentNode.m_data;
				int innerSum = 0;
				list<ListNode>::iterator iter = flagList.begin();
				while (iter != flagList.end()) {
					if (iter->m_start > currentListNode.m_start && iter->m_end < currentListNode.m_end) {
						innerSum += iter->m_total;
						flagList.erase(iter);
						iter = flagList.begin();
					} else {
						iter++;
					}
				}
				if (innerSum >= currentListNode.m_total) {
					isValid = false;
					break;
				} else {
					flagList.push_back(currentListNode);
				}
			}
		}
		if (dataStack.size() == 0) {
			if (isValid) {
				cout << ":-) Matrioshka!" << endl;
			} else {
				cout << ":-( Try again." << endl;
			}
		} else {
			cout << ":-( Try again." << endl;
		}
	}
}