#include <iostream>
#include <vector>
#include <deque>

struct Data {
	int m_data;

	// if one data is available(has not been visited), 
	// this value is true, else false.
	bool m_flag; 
};

using namespace std;

void GeneratePermutation (vector<Data>& data, deque<int>& result, int size) {
	if (size == 0)
		return;
	if (size == 1) {
		deque<int>::iterator resultIter = result.begin();
		while (resultIter != result.end()) {
			cout << *resultIter << " ";
			resultIter++;
		}
		vector<Data>::iterator dataIter = data.begin();
		while (dataIter != data.end()) {
			if (dataIter->m_flag) {
				cout << dataIter->m_data << endl;
			}
			dataIter++;
		}
	} else {
		vector<Data>::iterator currentIter = data.begin();
		while (currentIter != data.end()) {
			// notice the two conditions sequence, if we use
			// "currentIter != data.end() && !currentIter->m_flag"
			// the program will crash because the last element doesn't
			// has the m_flag field.
			while (currentIter != data.end() && !currentIter->m_flag) {
				currentIter++;
			}
			if (currentIter == data.end())
				break;
			int thisElemnet = currentIter->m_data;
			result.push_back(thisElemnet);
			currentIter->m_flag = false;
			GeneratePermutation(data, result, size - 1);
			result.pop_back();
			currentIter->m_flag = true;
			currentIter++;   
		}
	}
}

int main () {
	int num;
	cin >> num;

	// generate linked list.
	vector<Data> dataVector;
	for (int i = 0; i < num; i++) {
		Data currentElement;
		currentElement.m_data = i + 1;
		currentElement.m_flag = true;
		// cannot use dataVector.push_back(Data(i + 1, true)) here
		// because we haven't define the constructor of Data.
		dataVector.push_back(currentElement);
	}

	deque<int> resultDqueue;  
	GeneratePermutation(dataVector, resultDqueue, num);
}

/* 
1. Notice inline bugs.
2. This algorithm can be optimized. Can be written more clearly and get
   rid of <dqueue>. See analysis in GeneratePermutationVector2.
*/