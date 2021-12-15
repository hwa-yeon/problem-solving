#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int T, M, N, K, x, y;
struct point {
	int X;
	int Y;
	double Dist;

	bool operator < (const point& p) const
	{
		if (this->Dist != p.Dist) return this->Dist < p.Dist;
		else {
			if (this->X != p.X) return this->X < p.X;
			else return this->Y < p.Y;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> M >> N >> K;
		priority_queue<point> stores;

		for (int i = 1; i <= M; i++) {
			cin >> x >> y;
			stores.push({ x, y, sqrt(pow(x, 2) + pow(y, 2)) });
			if (stores.size() > K) stores.pop();
		}
		for (int i = 1; i <= N; i++) {
			cin >> x >> y;
			stores.push({ x, y, sqrt(pow(x, 2) + pow(y, 2)) });
			stores.pop();
			cout << stores.top().X << " " << stores.top().Y << "\n";
		}
	} 

	return 0;
}