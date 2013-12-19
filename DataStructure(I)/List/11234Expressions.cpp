#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct BinTreeNode {
	char m_data;
	BinTreeNode* m_left;
	BinTreeNode* m_right;
};

int main() {
	int numOfCases;
	cin >> numOfCases;
	while (numOfCases--) {
		string data;
		cin >> data;
		int length = data.length();
		stack<BinTreeNode*> nodeStack;
		for (int i = 0; i < length; i++) {
			BinTreeNode* currentNode = new BinTreeNode;
			currentNode->m_data = data[i];
			if (data[i] <= 'z' && data[i] >= 'a') {
				currentNode->m_left = NULL;
				currentNode->m_right = NULL;
			} else {
				BinTreeNode* rightNode = nodeStack.top();
				nodeStack.pop();
				BinTreeNode* leftNode = nodeStack.top();
				nodeStack.pop();
				currentNode->m_left = leftNode;
				currentNode->m_right = rightNode;
			}
			nodeStack.push(currentNode);
		}
		stack<char> result;
		queue<BinTreeNode*> nodeQueue;
		nodeQueue.push(nodeStack.top());
		while (!nodeQueue.empty()) {
			BinTreeNode* currentNode = nodeQueue.front();
			nodeQueue.pop();
			if (currentNode->m_left != NULL) {
				nodeQueue.push(currentNode->m_left);
			}
			if (currentNode->m_right != NULL) {
				nodeQueue.push(currentNode->m_right);
			}
			result.push(currentNode->m_data);
		}
		while (!result.empty()) {
			char thisChar = result.top();
			result.pop();
			cout << thisChar;
		}
		cout << endl;
	}
}