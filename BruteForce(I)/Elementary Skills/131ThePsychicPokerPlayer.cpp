#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Card {
public:
	char m_value;
	char m_suit;
	Card() {}
	Card(char value, char suit) {
		m_value = value;
		m_suit = suit;
	}
};

enum ResultType {
	HIGHEST_CARD,
	ONE_PAIR,
	TWO_PAIRS,
	THREE_OF_A_KIND,
	STRAIGHT,
	FLUSH,
	FULL_HOUSE,
	FOUR_OF_A_KIND,
	STRAIGHT_FLUSH
};

// NOTICE:
// For the sake of brevity, we use a global variable here,
// think how to do better?
ResultType maxResult = HIGHEST_CARD;

ResultType GetResultType(const vector<Card>& data) {
	// get hash of the suit and value.
	// !!!CAN THIS CODE BE OPTIMIZED?
	vector<int> hashValue(13, 0);
	vector<int> hashSuit(4, 0);
	for (int i = 0; i < 5; i++) {
		switch (data[i].m_value) {
		case 'A':
			hashValue[0]++;
			break;
		case '2':
			hashValue[1]++;
			break;
		case '3':
			hashValue[2]++;
			break;
		case '4':
			hashValue[3]++;
			break;
		case '5':
			hashValue[4]++;
			break;
		case '6':
			hashValue[5]++;
			break;
		case '7':
			hashValue[6]++;
			break;
		case '8':
			hashValue[7]++;
			break;
		case '9':
			hashValue[8]++;
			break;
		case 'T':
			hashValue[9]++;
			break;
		case 'J':
			hashValue[10]++;
			break;
		case 'Q':
			hashValue[11]++;
			break;
		case 'K':
			hashValue[12]++;
			break;
		default:
			break;
		}
		switch (data[i].m_suit) {
		case 'C':
			hashSuit[0]++;
			break;
		case 'D':
			hashSuit[1]++;
			break;
		case 'H':
			hashSuit[2]++;
			break;
		case 'S':
			hashSuit[3]++;
			break;
		default:
			break;
		}
	}

	// check for every result type.
	bool isStraight = false;
	bool isFlush = false;
	vector<int>::iterator iter = hashSuit.begin();
	// NOTICE: DON'T FORGET "iter++".
	while (iter != hashSuit.end()) {
		if (*iter == 5) {
			isFlush = true;
			break;
		}
		iter++;
	}
	// NOTICE: MAKE SURE THE VECTOR IS IN BOUND.
	// logical optimization, the following are original logic.
	//for (int i = 0; i < 9; i++) {
	//	int j;
	//	for (j = i; j < i + 4; j++) {
	//		if (hashValue[j] == 1 && hashValue[j] != hashValue[j + 1]) {
	//			break;
	//		}
	//	}
	//	if (j == i + 3 && hashValue[j] == hashValue[j + 1]) {
	//		isStraight = true;
	//		break;
	//	}
	//}

	for (int i = 0; i < 9; i++) {
		bool isCurrentOneStraight = true;
		for (int j = i; j <= i + 4; j++) {
			if (hashValue[j] != 1) {
				isCurrentOneStraight = false;
				break;
			}
		}
		if (isCurrentOneStraight) {
			isStraight = true;
			break;
		}
	}

	// Ace can be the last element.
	if (!isStraight) {
		bool needToJudgeAce = true;
		for (int i = 9; i <= 12; i++) {
			if (hashValue[i] != 1) {
				needToJudgeAce = false;
				break;
			}
		}
		if (needToJudgeAce && hashValue[0] == 1) {
			isStraight = true;
		}
	}
	if (isStraight && isFlush) {
		return STRAIGHT_FLUSH;
	}
	if (isFlush) {
		return FLUSH;
	}
	if (isStraight) {
		return STRAIGHT;
	}
	int numOfPairs = 0;
	int numOfThree = 0;
	int numOfFour = 0;
	iter = hashValue.begin();
	while (iter != hashValue.end()) {
		if (*iter == 2) {
			numOfPairs++;
		}
		if (*iter == 3) {
			numOfThree++;
		}
		if (*iter == 4) {
			numOfFour++;
		}
		iter++;
	}
	if (numOfPairs == 1) {
		if (numOfThree == 1) {
			return FULL_HOUSE;
		} else {
			return ONE_PAIR;
		}
	}
	if (numOfPairs == 2) {
		return TWO_PAIRS;
	}
	if (numOfFour == 1) {
		return FOUR_OF_A_KIND;
	}
	if (numOfThree == 1 & numOfPairs == 0) {
		return THREE_OF_A_KIND;
	}
	return HIGHEST_CARD;
}

// Following are extremely UGLY code. Needs further review.
// Don't delete it!!!

//ResultType GetSubProblemResult (vector<Card>& data, int index) {
//	ResultType maxResult = HIGHEST_CARD;
//	int end = index + 4;
//	vector<Card> subData(5);
//	for (int i1 = 0; i1 <= end - 5 + 1; i1++) {
//		for (int i2 = i1 + 1; i2 <= end - 5 + 2; i2++) {
//			for (int i3 = i2 + 1; i3 <= end - 5 + 3; i3++) {
//				for (int i4 = i3 + 1; i4 <= end - 5 + 4; i4++) {
//					for (int i5 = i4 + 1; i5 <= end; i5++) {
//						subData[0] = data[i1];
//						subData[1] = data[i2];
//						subData[2] = data[i3];
//						subData[3] = data[i4];
//						subData[4] = data[i5];
//						ResultType currentResult = GetResultType(subData);
//						if (currentResult > maxResult) {
//							maxResult = currentResult;
//						}
//					}
//				}
//			}
//		}
//	}
//	return maxResult;
//}

void GetSubProblemResult (vector<Card>& data, vector<int>& resultSequence, int index, int currentIndex) {
	if (currentIndex == index) {
		vector<Card> tempData(data);
		for (int i = 0; i < index; i++) {
			tempData[resultSequence[i]] = data[5 + i];
		}
		ResultType currentResult = GetResultType(tempData);
		if (currentResult > maxResult) {
			maxResult = currentResult;
		}
	} else {
		int i;
		if (currentIndex == 0) {
			i = 0;
		} else {
			i = resultSequence[currentIndex - 1] + 1;
		}
		for (; i < 5; i++) {  // NOTICE MAGIC NUMBER!!!
			resultSequence[currentIndex] = i;
			GetSubProblemResult(data, resultSequence, index, currentIndex + 1);
		}
	}
}

int main() {
	string currentCard;
	string resultStringMap[] = {
		"highest-card",
		"one-pair",
		"two-pairs",
		"three-of-a-kind",
		"straight",
		"flush",
		"full-house",
		"four-of-a-kind",
		"straight-flush"
	};
	while (cin >> currentCard) {
		vector<Card> data;
		// store the first card.
		data.push_back(Card(currentCard[0], currentCard[1]));
		// store the remaining 9 cards.
		for (int i = 0; i < 9; i++) {
			cin >> currentCard;
			data.push_back(Card(currentCard[0], currentCard[1]));
		}
		// try to replace 1~5 cards from the deck and get the result.
		maxResult = GetResultType(data);
		vector<int> resultSequence(10);
		for (int i = 1; i <= 5; i++) {
			GetSubProblemResult(data, resultSequence, i, 0);
		}
		// output final result.
		cout << "Hand: ";
		for (int i = 0; i < 5; i++) {
			cout << data[i].m_value << data[i].m_suit << " ";
		}
		cout << "Deck: ";
		for (int i = 5; i < 10; i++) {
			cout << data[i].m_value << data[i].m_suit << " ";
		}
		cout << "Best hand: " << resultStringMap[maxResult] << endl;
	}
}

/*
1. The usage of enumeration.
2. How to get C(m, n)? The algorithm may be similar to permutation, needs
   further review. Currently using 5 nested for clause, not good.
3. Calculate the probability of these cases and review probability theories.
4. Notice the C(m, n) generation function. The previous solution to this 
   problem is incorrect, any other better methods to generate C(m, n)?
5. Search for better code for this problem.
*/