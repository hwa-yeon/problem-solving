#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, A, B, x, y, g, cost;
	cin >> T;
	while (T--) {
		cin >> A >> B >> x >> y;
		g = abs(A - B);
		cost = (g - (B % g)) * x;

		if (min(A, B) <= g)
			cost = min(cost, (B % g) * y);
		cout << g << " " << cost << "\n";
	}

	return 0;
}