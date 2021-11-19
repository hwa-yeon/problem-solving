#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, answer;
vector<int> houseArr;

bool check(int length) {
	int house = 1;
	int count = 0;

	for (int i = 1; i <= N; i++) {
		if (house <= houseArr[i]) {
			house = houseArr[i] + length;
			count = count + 1;
		}
		if (count == M) return true;
	}
	return false;
}

int solution(int left, int right) {
	int middle;
	if (left == right) return left;
	if (left + 1 == right) {
		if (check(right) == true) return right;
		else return left;
	}
	middle = (left + right) / 2;
	if (check(middle) == true) return solution(middle, right);
	else return solution(left, middle - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int input;

	houseArr.push_back(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input;
		houseArr.push_back(input);
	}
	answer = solution(1, houseArr[N] - 1);
	cout << answer;

	return 0;
}