#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, answer;
struct roadInfo
{
	int neighbor, distance;
};
vector<roadInfo>* house;
bool* visitedHouse;

int treeSearch(int u) {
	int maxDistance = 0;
	int secondMaxDistance = 0;
	int tmpDistance;

	visitedHouse[u] = true;
	for (int i = 0; i < house[u].size(); i++) {
		if (visitedHouse[house[u][i].neighbor] == false) {
			tmpDistance = treeSearch(house[u][i].neighbor) + house[u][i].distance;
			if (tmpDistance > maxDistance) swap(tmpDistance, maxDistance);
			if (tmpDistance > secondMaxDistance) swap(tmpDistance, secondMaxDistance);
		}
	}
	answer = max(answer, maxDistance + secondMaxDistance);
	return maxDistance;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int u, v, d;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		house = new vector<roadInfo>[N + 1];
		visitedHouse = new bool[N + 1];

		for (int j = 1; j < (N + 1); j++) {
			visitedHouse[j] = false;
		}

		for (int j = 1; j < N; j++) {
			cin >> u >> v >> d;
			house[u].push_back({ v,d });
			house[v].push_back({ u,d });
		}
		answer = 0;
		treeSearch(1);
		cout << answer << "\n";

		for (int j = 0; j < (N + 1); j++) {
			house[j].clear();
		}
		delete[] house;
		delete[] visitedHouse;
	}

	return 0;
}