#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

struct BinTreeNode {
	int m_data;
	int m_total;
	BinTreeNode* m_left;
	BinTreeNode* m_right;
};

BinTreeNode* BuildBinTree(const string& data, int start, int end) {
	if (end == start + 1) {
		return NULL;
	}
	BinTreeNode* currentNode = new BinTreeNode;
	int nextLeft = start + 1;
	while (data[nextLeft] != '(') {
		nextLeft++;
	}
	string currentNumStr = data.substr(start + 1, nextLeft - start - 1);
	stringstream sstream;
	sstream << currentNumStr;
	int currentNumInt;
	sstream >> currentNumInt;
	int nextRight = nextLeft + 1;
	stack<char> tempStack;
	tempStack.push(data[nextLeft]);
	while (!tempStack.empty()) {
		if (data[nextRight] == '(') {
			tempStack.push(data[nextRight]);
		} else if (data[nextRight] == ')') {
			tempStack.pop();
			if (tempStack.empty()) {
				break;
			}
		}
		nextRight++;
	}
	currentNode->m_data = currentNumInt;
	currentNode->m_total = currentNumInt;
	currentNode->m_left = BuildBinTree(data, nextLeft, nextRight);
	currentNode->m_right = BuildBinTree(data, nextRight + 1, end - 1);
	return currentNode;
}

int main () {
	int target;
	while (cin >> target) {
		// get current input case's string.
		char currentChar;
		stack<char> tempStack;
		string data;
		while (true) {
			cin >> currentChar;
			if (currentChar != '(' && currentChar != ')' && currentChar != '-' && (currentChar > '9' || currentChar < '0')) {
				continue;
			}
			data.push_back(currentChar);
			if (currentChar == '(') {
				tempStack.push(currentChar);
			} else if (currentChar == ')') {
				tempStack.pop();
				if (tempStack.empty()) {
					break;
				}
			}
		}
		BinTreeNode* root;
		root = BuildBinTree(data, 0, data.size() - 1);

		// BFS.
		if (root == NULL) {
			cout << "no" << endl;
		} else {
			stack<BinTreeNode*> nodeStack;
			nodeStack.push(root);
			bool isValid = false;
			while (!nodeStack.empty()) {
				BinTreeNode* currentNode = nodeStack.top();
				nodeStack.pop();
				if (currentNode->m_left == NULL && currentNode->m_right == NULL) {
					if (currentNode->m_total == target) {
						isValid = true;
					} 
				} else {
					if (currentNode->m_left != NULL) {
						currentNode->m_left->m_total = currentNode->m_left->m_data + currentNode->m_total;
						nodeStack.push(currentNode->m_left);
					}
					if (currentNode->m_right != NULL) {
						currentNode->m_right->m_total = currentNode->m_right->m_data + currentNode->m_total;
						nodeStack.push(currentNode->m_right);
					}
				}
			}
			if (isValid) {
				cout << "yes" << endl;
			} else {
				cout << "no" << endl;
			}
		}
	}
}