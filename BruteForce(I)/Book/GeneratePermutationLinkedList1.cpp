#include <iostream>
#include <list>
#include <deque>

using namespace std;

void GeneratePermutation (list<int>& data, deque<int>& result) {
	if (data.size() == 0)
		return;
	if (data.size() == 1) {
		deque<int>::iterator iter = result.begin();
		while (iter != result.end()) {
			cout << *iter << " ";
			iter++;
		}
		cout << data.front() << endl;   //!!!!!!!!
	} else {
		list<int>::iterator currentIter = data.begin();
		while (currentIter != data.end()) {
			list<int>::iterator nextIter = currentIter;
			nextIter++;             // NOTICE!!!
			int thisElemnet = *currentIter;
			result.push_back(thisElemnet);
			data.erase(currentIter);
			GeneratePermutation(data, result);
			result.pop_back();
			if (nextIter != data.end()) {
				data.insert(nextIter, thisElemnet);
			} else {  // the last element
				data.push_back(thisElemnet);
			}
			// Notice: After calling data.erase, the currentIter is invalid
			// right now, so we couldn't use currentIter++ here, but need to
			// use currentIter = nextIter.
			currentIter = nextIter;   
		}
	}
}

int main () {
	int num;
	cin >> num;

	// generate linked list.
	list<int> dataList;
	for (int i = 0; i < num; i++) {
		dataList.push_back(i + 1);
	}

	deque<int> resultDqueue;  
	GeneratePermutation(dataList, resultDqueue);

// 	list<int>::iterator iter = dataList.begin();
// 	while (iter != dataList.end()) {
// 		cout << *iter << " ";
// 		iter++;
// 	}
}

/* (NOT COMPLETE!!!)
1. Review STL container <list>.
2. Review STL container <dqueue>.
3. Notice we cannot use '+' operator to the iterator.
4. There is a fatal error in this algorithm, we use the erase method of the list.
   However the problem is we currently use "nextIter" to locate the position we
   want to insert the element. Notice that we still have a recursive call after
   deleting the element. Thus it is obvious that the element which nextIter points
   to will be delete. The STL is using dynamic memory allocation, thus the pointer
   "nextIter" will be invalid.
5. Maybe there are some solutions to solve (4), needs further review.
*/