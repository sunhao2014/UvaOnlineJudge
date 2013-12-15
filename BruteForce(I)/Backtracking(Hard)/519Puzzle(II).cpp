//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//struct Data {
//	char m_left;
//	char m_right;
//	char m_top;
//	char m_bottom;
//};
//
//int n, m;
//vector<Data> data(40);
//
//bool HaveSolution(vector< vector<Data> >& flags, vector<bool> visited, int x, int y) {
//	if (x == n) {
//		return true;
//	} else {
//		vector<Data> cannotBePlacedElements;
//		for (int i = 0; i < n * m; i++) {
//			if (visited[i]) {
//				continue;
//			}
//			bool canBePlaced = true;
//			if (data[i].m_left != flags[x][y].m_left && flags[x][y].m_left != 'X') {
//				canBePlaced = false;
//			}
//			if (data[i].m_right != flags[x][y].m_right && flags[x][y].m_right != 'X') {
//				canBePlaced = false;
//			}
//			if (data[i].m_top != flags[x][y].m_top && flags[x][y].m_top != 'X') {
//				canBePlaced = false;
//			}
//			if (data[i].m_bottom != flags[x][y].m_bottom && flags[x][y].m_bottom != 'X') {
//				canBePlaced = false;
//			}
//
//			// pruning: if this element is tried and cannot be place in 
//			// the current place, then skip.
//			vector<Data>::iterator iter;
//			for (iter = cannotBePlacedElements.begin(); iter != cannotBePlacedElements.end(); ++iter) {
//				if ((data[i].m_left == iter->m_left) &&
//					(data[i].m_right == iter->m_right) &&
//					(data[i].m_top == iter->m_top) &&
//					(data[i].m_bottom == iter->m_bottom)) {
//						canBePlaced = false;
//						break;
//				}
//			}
//
//			if (canBePlaced) {
//				int xNew, yNew;
//				xNew = x;
//				yNew = y + 1;
//				if (y == m - 1) {
//					yNew = 0;
//					xNew = x + 1;
//				}
//				// put data[i] on position (x,y).
//				// only have influence on the right and bottom elements.
//				char rightOrigin;
//				char bottomOrigin;
//				if (x != n - 1) {
//					bottomOrigin = flags[x + 1][y].m_top;
//					switch (data[i].m_bottom)
//					{
//					case 'F':
//						flags[x + 1][y].m_top = 'F';
//						break;
//					case 'I':
//						flags[x + 1][y].m_top = 'O';
//						break;
//					case 'O':
//						flags[x + 1][y].m_top = 'I';
//						break;
//					}
//				}
//				if (y != m - 1) {
//					rightOrigin = flags[x][y + 1].m_left;
//					switch (data[i].m_right)
//					{
//					case 'F':
//						flags[x][y + 1].m_left = 'F';
//						break;
//					case 'I':
//						flags[x][y + 1].m_left = 'O';
//						break;
//					case 'O':
//						flags[x][y + 1].m_left = 'I';
//						break;
//					}
//				}
//				visited[i] = true;
//				if (HaveSolution(flags, visited, xNew, yNew)) {
//					return true;
//				}
//
//				// this element cannot be placed on this place, so
//				// add it to the cannotBePlaced list.
//				cannotBePlacedElements.push_back(data[i]);
//
//				// clear the flags.
//				if (x != n - 1) {
//					flags[x + 1][y].m_top = bottomOrigin;
//				}
//				if (y != m - 1) {
//					flags[x][y + 1].m_left = rightOrigin;
//				}
//				visited[i] = false;
//			}
//		}
//		return false;
//	}
//}
//
//int main() {
//	while (true) {
//		cin >> n >> m;
//		if (n == 0 && m == 0) {
//			break;
//		}
//		data.clear();
//		data.resize(40);
//		int iCount = 0;
//		int oCount = 0;
//		vector< vector<Data> > flags(n, vector<Data>(m));
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				if (i == 0) {
//					flags[i][j].m_top = 'F';
//				} else {
//					flags[i][j].m_top = 'X';
//				}
//
//				if (i == n - 1) {
//					flags[i][j].m_bottom = 'F';
//				} else {
//					flags[i][j].m_bottom = 'X';
//				}
//
//				if (j == 0) {
//					flags[i][j].m_left = 'F';
//				} else {
//					flags[i][j].m_left = 'X';
//				}
//
//				if (j == m - 1) {
//					flags[i][j].m_right = 'F';
//				} else {
//					flags[i][j].m_right = 'X';
//				}
//			}
//		}
//		for (int i = 0; i < n * m; i++) {
//			for (int j = 0; j < 4; j++) {
//				char temp;
//				cin >> temp;
//				if (temp == 'I') {
//					iCount++;
//				} else if (temp == 'O') {
//					oCount++;
//				}
//				switch (j) {
//				case 0:
//					data[i].m_top = temp;
//					break;
//				case 1:
//					data[i].m_right = temp;
//					break;
//				case 2:
//					data[i].m_bottom = temp;
//					break;
//				case 3:
//					data[i].m_left = temp;
//					break;
//				}
//			}
//		}
//		vector<bool> visted(40, false);
//		if (iCount != oCount) {
//			cout << "NO" << endl;
//		} else {
//			if (HaveSolution(flags, visted, 0, 0)) {
//				cout << "YES" << endl;
//			} else {
//				cout << "NO" << endl;
//			}
//		}
//	}
//}
//
//// Notice: TLE(2)
//// 1. Note the pruning strategy.
//// 2. After adding the pruning, it is still TLE, however after adding
////    the initial judge of iCount != oCount, it is accepted.
////