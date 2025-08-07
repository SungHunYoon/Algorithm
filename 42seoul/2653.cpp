#include <iostream>
#include <vector>

using namespace std;

int N;
int P[101];
int V[101];
int A[101][101];

int find(int idx) {
	if (P[idx] == idx) {
		return idx;
	}
	P[idx] = find(P[idx]);
	return P[idx];
}

bool makeUnion(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) {
		return false;
	}
	if (a > b) {
		P[a] = b;
	} else {
		P[b] = a;
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		P[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			if (A[i][j] == 0) {
				makeUnion(i, j);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (A[i][j] && find(i) == find(j)) {
				cout << "0\n";
				return 0;
			}
		}
	}
	vector<vector<int>> answer;
	int cnt = 0;
	while (cnt < N) {
		int idx = 0;
		vector<int> B;
		for (int i = 1; i <= N; i++) {
			if (V[i]) continue;
			if (idx == 0) {
				idx = i;
			}
			if (idx != find(i)) continue;
			B.push_back(i);
			V[i] = 1;
			cnt++;
		}
		if (B.size() == 1) {
			cout << "0\n";
			return 0;
		}
		answer.push_back(B);
	}
	cout << answer.size() << '\n';
	for (auto a : answer) {
		for (auto b : a) {
			cout << b << ' ';
		}
		cout << '\n';
	}
	return 0;
}