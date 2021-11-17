#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, A, B;
string S;

struct Node
{
	int parent = 0;
	vector<int> children;
	int length = 0;
};

Node* tree;
int* directory;

void TreeTraversal(int u) {
	if (u == 1) directory[u] = 4;
	else {
		directory[u] = directory[tree[u].parent] + 1 + tree[u].length;
	}
	for (int i = 0; i < tree[u].children.size(); i++) {
		TreeTraversal(tree[u].children[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;

		tree = new Node[N+1];
		directory = new int[N+1];

		for (int j = 1; j <= (N - 1); j++) {
			cin >> A >> B;
			tree[A].children.push_back(B);
			tree[B].parent = A;
		}
		for (int j = 1; j <= N; j++) {
			cin >> S;
			tree[j].length = S.size();
		}

		TreeTraversal(1);

		for (int j = 1; j <= N; j++) {
			cout << directory[j] << "\n";
		}

		delete[] tree;
		delete[] directory;
	}

	return 0;
}