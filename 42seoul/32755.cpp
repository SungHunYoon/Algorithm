#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, A, B;
vector<int> V[501];
int T[501];

void dfs(int idx, bool r) {
	T[idx] = r ? 1 : 2;
	for (auto v : V[idx])
		if (T[v] == 0) dfs(v, !r);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> A >> B;
		V[A].push_back(B);
		V[B].push_back(A);
	}
	dfs(1, true);
	int R = 0, B = 0;
	for (int i = 1; i <= N; i++) {
		if (T[i] == 1) R++;
		else B++;
	}
	if (R == 1 || B == 1) cout << N - 1 << '\n';
	else cout << N << '\n';
	return 0;
}