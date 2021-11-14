#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n;

	for (int i = 0; i < n; i++) {
		vector<int> v;
		vector<int> sv;
		vector<int> lv;
		int num, push;

		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> num;
			if (num == 1) {
				cin >> push;
				v.push_back(push);

				if (v.size() == 1) {
					sv.push_back(push);
					lv.push_back(push);
				}

				if (v.back() <= sv.back()) {
					sv.push_back(v.back());
				}
				if (v.back() >= lv.back()) {
					lv.push_back(v.back());
				}

				cout << sv.back() << " " << lv.back() << "\n";
			}
			else if (num == 2) {
				if (!v.empty()) {
					if (v.back() == sv.back()) {
						sv.pop_back();
					}
					if (v.back() == lv.back()) {
						lv.pop_back();
					}
					v.pop_back();
				}
			}
		}
	}

	return 0;
}