#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, answer, flag;
	int num1, num2;

	cin >> T;
	for (int i = 0; i < T; i++) {
		vector<int> inha;
		vector<int> birong;
		vector<pair<int, int>> sum;

		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> num1 >> num2;
			inha.push_back(num1);
			birong.push_back(num2);
			sum.push_back(pair<int, int>(num1 + num2, j));
		}
		sort(sum.begin(), sum.end(), greater<>());
		answer = 0;
		flag = 1;

		for (int j = 0; j < N; j++) {
			if (flag == 1) {
				answer += inha[sum[j].second];
				flag = 0;
			}
			else if (flag == 0) {
				answer -= birong[sum[j].second];
				flag = 1;
			}
		}
		cout << answer << "\n";
	}

	return 0;
}