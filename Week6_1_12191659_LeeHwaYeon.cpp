#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<pair<int,int>> customer;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> counterPQ;

vector<int> costAnswer;
int N, M, timeAnswer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int t, c;
		cin >> t >> c;
		customer.push_back({ t,c });
	}
	for (int i = 0; i < N; i++) {
		counterPQ.push({ customer[i].first, i });
		costAnswer.push_back(customer[i].second);
		timeAnswer = max(timeAnswer, customer[i].first);
	}
	for (int i = N; i < M; i++) {
		pair<int,int> counterTemp = counterPQ.top();
		counterPQ.pop();
		counterTemp.first += customer[i].first;
		costAnswer[counterTemp.second] += customer[i].second;
		timeAnswer = max(timeAnswer, counterTemp.first);
		counterPQ.push(counterTemp);
	}
	cout << timeAnswer << "\n";
	for (int i = 0; i < N; i++) {
		cout << costAnswer[i] << "\n";
	}

	return 0;
}