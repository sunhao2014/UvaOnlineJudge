#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct DListNode {
	int m_data;
	DListNode* m_previous;
	DListNode* m_next;
};

int main () {
	while (true) {
		int n, m, k;
		cin >> n >> m >> k;
		if (n == 0 && m == 0 && k == 0) {
			break;
		}
		DListNode* head;
		DListNode* pre;
		for (int i = 1; i <= n; i++) {
			DListNode* currentNode = new DListNode;
			currentNode->m_data = i;
			if (i == 1) {
				pre = currentNode;
				head = currentNode;
			} else {
				pre->m_next = currentNode;
				head->m_previous = currentNode;
				currentNode->m_next = head;
				currentNode->m_previous = pre;
				pre = currentNode;
			}
		}
		int count = n;
		DListNode* leftCounter = head;
		DListNode* rightCounter = head->m_previous;
		while (count > 0) {
			for (int i = 1; i < m; i++) {
				leftCounter = leftCounter->m_next;
			}
			for (int i = 1; i < k; i++) {
				rightCounter = rightCounter->m_previous;
			}
			// delete the selected nodes
			if (leftCounter->m_data == rightCounter->m_data) {
				DListNode* thisNode = leftCounter;
				leftCounter = leftCounter->m_next;
				rightCounter = rightCounter->m_previous;
				thisNode->m_previous->m_next = thisNode->m_next;
				thisNode->m_next->m_previous = thisNode->m_previous;
				printf("%3d", thisNode->m_data);
				delete thisNode;
				count--;
			} else {
				DListNode* leftNode = leftCounter;
				DListNode* rightNode = rightCounter;
				if (leftNode->m_next == rightNode) {
					leftCounter = leftCounter->m_next->m_next;
					rightCounter = rightCounter->m_previous->m_previous;
				} else {
					leftCounter = leftCounter->m_next;
					rightCounter = rightCounter->m_previous;
				}
				leftNode->m_previous->m_next = leftNode->m_next;
				leftNode->m_next->m_previous = leftNode->m_previous;
				printf("%3d", leftNode->m_data);
				delete leftNode;
				rightNode->m_previous->m_next = rightNode->m_next;
				rightNode->m_next->m_previous = rightNode->m_previous;
				printf("%3d", rightNode->m_data);
				delete rightNode;
				count -= 2;
			}
			if (count > 0) {
				printf(",");
			}
		}
		printf("\n");
	}
}