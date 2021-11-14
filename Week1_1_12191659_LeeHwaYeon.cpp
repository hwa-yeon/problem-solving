#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, K;
	string S;

	cin >> T;
	for (int n = 0; n < T; n++) {
		cin >> S;
		cin >> K;

		for (int i = 0; i < K; i++) {
			for (int j = 0; ; j += 2*K) {
				if (j + i >= S.length()) break;
				cout << S[j + i];
				if (j + 2 * K - i - 1 >= S.length()) break;
				cout << S[j + 2 * K - i - 1];
			}
		}
		cout << "\n";
	}

	return 0;
}