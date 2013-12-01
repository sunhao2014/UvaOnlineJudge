//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void GetMaxRoadLength (vector< vector<int> >& data, vector< vector<int> >& visitd, int currentPoint, int n, int currentLength, int& maxLength) {
//	bool hasRoadToGo = false;
//	for (int i = 0; i < n; i++) {
//		if (data[currentPoint][i] == 1 && visitd[currentPoint][i] == 0) {
//			hasRoadToGo = true;
//			visitd[currentPoint][i] = 1;
//			visitd[i][currentPoint] = 1;
//			currentLength++;
//			GetMaxRoadLength(data, visitd, i, n, currentLength, maxLength);
//			visitd[currentPoint][i] = 0;
//			visitd[i][currentPoint] = 0;
//			currentLength--;
//		}
//	}
//	if (!hasRoadToGo) {
//		if (currentLength > maxLength) {
//			maxLength = currentLength;
//		}
//	}
//}
//
//int main() {
//	while (true) {
//		int n, m;
//		cin >> n >> m;
//		if (n == 0 && m == 0) {
//			break;
//		}
//		vector< vector<int> > data(n, vector<int>(n, 0));  // NOTICE THIS USAGE.
//		for (int i = 0; i < m; i++) {
//			int x, y;
//			cin >> x >> y;
//			// undirected graph.
//			data[x][y] = 1;
//			data[y][x] = 1;
//		}
//		vector< vector<int> > visited(n, vector<int>(n, 0));
//		int maxLength = 0;
//		for (int i = 0; i < n; i++) {
//			int currentLength = 0;
//			// get max road length with the current visited vector
//			// and starts with i.
//			GetMaxRoadLength(data, visited, i, n, 0, currentLength);
//			if (currentLength > maxLength) {
//				maxLength = currentLength;
//			}
//		}
//		cout << maxLength << endl;
//	}
//}
//
////
//// 1. Need to learn from other methods, search from the Internet.
//// 2. The data structure for graph, now we are using the adjacent matrix.
//// 3. Review for the DFS.
//// 4. Time complicity analysis.
////