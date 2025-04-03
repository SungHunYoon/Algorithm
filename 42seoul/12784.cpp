#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int T, N, M;

int dfs(vector<vector<ii>> &V, vector<bool> &v, int idx, int pCnt) {
	v[idx] = true;
	if (idx != 1 && V[idx].size() == 1)
		return pCnt;
	int ret = 0;
	for (auto [d, n] : V[idx]) {
		if (v[n]) continue;
		ret += dfs(V, v, n, d);
	}
	return min(ret, pCnt);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> N >> M;
		vector<vector<ii>> V(N + 1);
		vector<bool> v(N + 1);
		for (int i = 0; i < M; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			V[a].push_back({c, b});
			V[b].push_back({c, a});
		}
		cout << dfs(V, v, 1, 1e9) << '\n';
	}
	return 0;
}