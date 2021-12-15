#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, M, A, B, answer;
vector<int>* graph;
int* visit;

void Dfs(int u) {
	visit[u] = 1;
	for (int i = 0; i < graph[u].size(); i++) {
		int v = graph[u][i];
		if (visit[v] == 0) Dfs(v);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N >> M;
		graph = new vector<int>[N + 1];
		visit = new int[N + 1];

		for (int i = 0; i < M; i++) {
			cin >> A >> B;
			graph[A].push_back(B);
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) visit[j] = 0;
			Dfs(i);
			answer = 0;
			for (int j = 1; j <= N; j++) {
				answer = answer + visit[j];
			}
			cout << answer - 1 << " ";
		}
		cout << "\n";

		for (int i = 0; i <= N; i++) {
			graph[i].clear();
		}
		delete[] graph;
		delete[] visit;
	}

	return 0;
}