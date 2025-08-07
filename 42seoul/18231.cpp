#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
vector<int> V[2001];
bool A[2001];
bool B[2001];
int D[2001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		V[u].push_back(v);
		V[v].push_back(u);
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		int k;
		cin >> k;
		A[k] = 1;
	}
	vector<int> C;
	for (int i = 1; i <= N; i++) {
		if (!A[i]) continue;
		bool flag = true;
		for (auto v : V[i]) {
			if (!A[v]) flag = false;
		}
		if (!flag) continue;
		C.push_back(i);
		B[i] = true;
		for (auto v : V[i]) {
			B[v] = true;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (A[i] != B[i]) {
			cout << "-1\n";
			return 0;
		}
	}
	cout << C.size() << '\n';
	for (auto c : C) {
		cout << c << ' ';
	}
	cout << '\n';

	return 0;
}