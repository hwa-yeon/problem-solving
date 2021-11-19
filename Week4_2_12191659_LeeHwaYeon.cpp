#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x1, y1, x2, y2, x3, y3, x4, y4;
	int T, X, Y;
	
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> x3 >> y3 >> x4 >> y4;

		if (x1 > x2) {
			swap(x1, x2);
			swap(y1, y2);
		}
		if (x3 > x4) {
			swap(x3, x4);
			swap(y3, y4);
		}

		if (x1 == x2 && x3 == x4) {
			if (x1 != x3) cout << "1";
			else if (x1 == x3) {
				if (y1 > y2) swap(y1, y2);
				if (y3 > y4) swap(y3, y4);

				if (y1 > y4 || y3 > y2) cout << "1";
				if (y1 == y4 || y3 == y2) cout << "2";
				if ((y1 <= y3 && y4 <= y2) || (y3 <= y1 && y2 <= y4)) cout << "4";
				if ((y1 > y3 && y1 < y4 && y4 < y2) || (y3 > y1 && y3 < y2 && y2 < y4)) cout << "3";
			}
		}
		else if (x1 == x2 && y3 == y4) {
			X = x1;
			Y = y3;
			if ((min(y1, y2) <= Y && Y <= max(y1, y2)) && (x3 <= X && X <= x4)) cout << "2";
			else cout << "1";
		}
		else if (y1 == y2 && x3 == x4) {
			X = x3;
			Y = y1;
			if ((x1 <= X && X <= x2) && (min(y3, y4) <= Y && Y <= max(y3, y4))) cout << "2";
			else cout << "1";
		}
		else if (y1 == y2 && y3 == y4) {
			if (y1 != y3) cout << "1";
			else if (y1 == y3) {
				if (x1 > x4 || x3 > x2) cout << "1";
				if (x1 == x4 || x3 == x2) cout << "2";
				if ((x1 <= x3 && x4 <= x2) || (x3 <= x1 && x2 <= x4)) cout << "4";
				if ((x1 > x3 && x1 < x4 && x4 < x2) || (x3 > x1 && x3 < x2 && x2 < x4)) cout << "3";
			}
		}
		cout << "\n";
	}

	return 0;
}