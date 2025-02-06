#include <iostream>

using namespace std;

int N, M, A, B, C;
int T[11][11];
bool V[11];

int dfs(int idx, int maxCost, int cost) {
	if (cost > C)
		return 1e9;
	if (idx == B)
		return maxCost;
	int ret = 1e9;
	for (int i = 1; i <= 10; i++) {
		if (!T[idx][i] || V[i]) continue;
		V[i] = true;
		ret = min(ret, dfs(i, max(maxCost, T[idx][i]), cost + T[idx][i]));
		V[i] = false;
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> A >> B >> C;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		T[a][b] = T[b][a] = c;
	}
	V[A] = true;
	int answer = dfs(A, 0, 0);
	cout << (answer == 1e9 ? -1 : answer) << '\n';
	return 0;
}