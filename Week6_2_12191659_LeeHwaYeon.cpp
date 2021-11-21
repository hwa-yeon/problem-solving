#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct point {
	int x, y;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N;
	int** check;
	bool** visited;
	int dx[9] = { 0, 0, 0, 1, 1, 1, -1, -1, -1 };
	int dy[9] = { 0, 1, -1, 0, -1, 1, 0, -1, 1 };
	point inha, safe, knight, gunner;

	cin >> T;
	while (T--) {
		cin >> N;

		check = new int* [N + 1];
		visited = new bool* [N + 1];
		for (int i = 0; i < N + 1; i++) {
			check[i] = new int[N + 1];
			visited[i] = new bool[N + 1];
		}
		cin >> inha.x >> inha.y >> safe.x >> safe.y;
		cin >> knight.x >> knight.y >> gunner.x >> gunner.y;

		for (int i = 0; i < N + 1; i++) {
			for (int j = 0; j < N + 1; j++) {
				check[i][j] = 0;
				visited[i][j] = false;
			}
		}

		for (int i = 1; i <= 8; i++) {
			for (int j = 1; j < N + 1; j++) {
				if ((gunner.x + dx[i] * j == 0) || (gunner.x + dx[i] * j == N + 1) || (gunner.y + dy[i] * j == 0) || (gunner.y + dy[i] * j == N + 1))
					break;
				if ((gunner.x + dx[i] * j == knight.x) && (gunner.y + dy[i] * j == knight.y))
					break;
				check[gunner.x + dx[i] * j][gunner.y + dy[i] * j] = -1;
			}
		}
		for (int i = 1; i <= 8; i++) {
			if ((knight.x + dx[i] == 0) || (knight.x + dx[i] == N + 1) || (knight.y + dy[i] == 0) || (knight.y + dy[i] == N + 1))
				continue;
			check[knight.x + dx[i]][knight.y + dy[i]] = -1;
		}
		queue<point> que;
		que.push({ inha.x,inha.y });
		while (!que.empty()) {
			point now = que.front();
			que.pop();
			visited[now.x][now.y] = true;
			for (int i = 1; i <= 8; i++) {
				if ((now.x + dx[i] == 0) || (now.x + dx[i] == N + 1) || (now.y + dy[i] == 0) || (now.y + dy[i] == N + 1))
					continue;
				if ((check[now.x + dx[i]][now.y + dy[i]] != 0) || (visited[now.x + dx[i]][now.y + dy[i]]))
					continue;
				check[now.x + dx[i]][now.y + dy[i]] = check[now.x][now.y] + 1;
				que.push({ now.x + dx[i], now.y + dy[i] });
			}
		}
		cout << check[safe.x][safe.y] << "\n";

		for (int i = 0; i < N + 1; i++) {
			delete[] check[i];
			delete[] visited[i];
		}
		delete[] check;
		delete[] visited;
	}
	return 0;
}