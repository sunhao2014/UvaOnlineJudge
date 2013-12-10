#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

vector< bitset<16> > requirment(12);
vector< bitset<16> > mask(12);
int currentPerson;

bool IsValidAnswer(int num) {
	bool result = true;
	for (int i = 0; i < currentPerson; i++) {
		if (((~(num ^ requirment[i].to_ulong())) & (mask[i].to_ulong())) == 0) {  // core bit manipulation.
			result = false;
			break;
		}
	}
	return result;
}

int main () {
	char currentOperator;
	currentPerson = 0;
	while (cin >> currentOperator) {
		if (currentOperator == '.'){
			int n = (1 << 16) - 1;
			bool haveValidAnswer = false;
			for (int i = 0; i < n; i++) {
				if (IsValidAnswer(i)) {
					haveValidAnswer = true;
					cout << "Toppings: ";
					for (int j = 0; j < 16; j++) {
						if ((i & 0x01) == 1) {
							cout << (char)(j + 'A');
						}
						i >>= 1;
					}
					cout << endl;
					break;
				}
			}
			if (!haveValidAnswer) {
				cout << "No pizza can satisfy these requests." << endl;
			}
			requirment.clear();
			requirment.resize(12);
			mask.clear();
			mask.resize(12);
			currentPerson = 0;
		} else if (currentOperator == ';') {
			currentPerson++;
		} else {
			char currentRequirement;
			cin >> currentRequirement;
			if (currentOperator == '+') {
				requirment[currentPerson][currentRequirement - 'A'] = 1;
			} else if (currentOperator == '-') {
				requirment[currentPerson][currentRequirement - 'A'] = 0;
			}
			mask[currentPerson][currentRequirement - 'A'] = 1;
		}
	}
}


// BLOCKED AT PHASE 1.
// 1. Note that we can use the bit operation to judge whether it
//    is a proper solution.
// 2. The usage of vector.clear().
//

