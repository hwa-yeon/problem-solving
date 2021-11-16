#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, M, K;
	int answer = 0;
	string S;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;

		vector<string> sentence;
		vector<queue<string>> word;
		queue<string> q;

		for (int j = 0; j < M; j++) {
			cin >> S;
			sentence.push_back(S);
		}
		for (int j = 0; j < N; j++) {
			cin >> K;
			word.push_back(q);
			for (int k = 0; k < K; k++) {
				cin >> S;
				word[j].push(S);
			}
		}

		for (int j = 0; j < M; j++) {
			answer = 0;
			for (int k = 0; k < N; k++) {
				if (sentence[j] == word[k].front()) {
					word[k].pop();
					answer = 1;
					break;
				}
			}
			if (answer == 0) break;
		}
		cout << answer << "\n";
	}

	return 0;
}