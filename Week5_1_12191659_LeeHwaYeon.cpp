#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N;
vector<int> signal;
vector<int> prefix;

void PrefixFunc() {
	prefix.push_back(0);
	int k = 0;
	
	for (int i = 1; i < N; i++) {
		while (k > 0 && signal[i] != signal[k])
			k = prefix[k - 1];
		if (signal[i] == signal[k])
			k = k + 1;
		prefix.push_back(k);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> num;
			signal.push_back(num);
		}
		PrefixFunc();
		for (int j = 0; j < (N - prefix[N-1]); j++) {
			cout << signal[j] << " ";
		}
		cout << "\n";
		signal.clear();
		prefix.clear();
	}

	return 0;
}