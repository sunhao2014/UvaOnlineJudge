//#include <iostream>
//#include <vector>
//#include <stack>
//#include <string>
//#include <sstream>
//
//using namespace std;
//
//struct BinTreeNode {
//	int m_data;
//	int m_total;
//	BinTreeNode* m_left;
//	BinTreeNode* m_right;
//};
//
//BinTreeNode* RebuildBinTree (int inOrderStart, int inOrderEnd, int postOrderStart, vector<int>& inOrderData, vector<int>& postOrderData) {
//	int currentIndex;
//	for (currentIndex = inOrderStart; currentIndex <= inOrderEnd; currentIndex++) {
//		if (inOrderData[currentIndex] == postOrderData[postOrderStart]) {
//			break;
//		}
//	}
//	int leftLength = currentIndex - inOrderStart;
//	int rightLength = inOrderEnd - currentIndex;
//	BinTreeNode* root = new BinTreeNode;
//	root->m_data = inOrderData[currentIndex];
//	root->m_total = root->m_data;
//	if (leftLength <= 0) {
//		root->m_left = NULL;
//	} else {
//		int postIndex;
//		if (rightLength <= 0) {
//			postIndex = postOrderStart - 1;
//		} else {
//			postIndex = postOrderStart - 1 - rightLength;
//		}
//		root->m_left = RebuildBinTree(inOrderStart, currentIndex - 1, postIndex, inOrderData, postOrderData);
//	}
//	if (rightLength <= 0) {
//		root->m_right = NULL;
//	} else {
//		root->m_right = RebuildBinTree(currentIndex + 1, inOrderEnd, postOrderStart - 1, inOrderData, postOrderData);
//	}
//	return root;
//}
//
//int main () {
//	string inOrderStr, postOrderStr;
//	while (getline(cin, inOrderStr)) {
//		getline(cin, postOrderStr);
//		stringstream inOrderTemp, postOrderTemp;
//		vector<int> inOrderData, postOrderData;
//		inOrderTemp << inOrderStr;
//		postOrderTemp << postOrderStr;
//		int temp;
//		while (inOrderTemp >> temp) {
//			inOrderData.push_back(temp);
//		}
//		while (postOrderTemp >> temp) {
//			postOrderData.push_back(temp);
//		}
//		BinTreeNode* root;
//		root = RebuildBinTree(0, inOrderData.size() - 1, postOrderData.size() - 1, inOrderData, postOrderData);
//		
//		// BFS.
//		stack<BinTreeNode*> nodeStack;
//		nodeStack.push(root);
//		int minLength = 99999999;
//		int minIndex = root->m_data;
//		while (!nodeStack.empty()) {
//			BinTreeNode* currentNode = nodeStack.top();
//			nodeStack.pop();
//			if (currentNode->m_left == NULL && currentNode->m_right == NULL) {
//				if (currentNode->m_total < minLength) {
//					minLength = currentNode->m_total;
//					minIndex = currentNode->m_data;
//				} else if (currentNode->m_total == minLength && currentNode->m_data < minIndex) {
//					minIndex = currentNode->m_data;
//				} 
//			} else {
//				if (currentNode->m_left != NULL) {
//					currentNode->m_left->m_total = currentNode->m_left->m_data + currentNode->m_total;
//					nodeStack.push(currentNode->m_left);
//				}
//				if (currentNode->m_right != NULL) {
//					currentNode->m_right->m_total = currentNode->m_right->m_data + currentNode->m_total;
//					nodeStack.push(currentNode->m_right);
//				}
//			}
//		}
//		cout << minIndex << endl;
//	}
//}