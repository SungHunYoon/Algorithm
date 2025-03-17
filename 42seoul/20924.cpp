#include <iostream>
#include <vector>

using namespace std;
using ii = pair<int, int>;

int N, R, G, L;
vector<ii> V[200001];
bool visit[200001];

int dfs(int idx, int dis, bool flag) {
	if (!flag) {
		G = idx;
		if (idx == R && V[idx].size() >= 2)
			return dis;
		else if (V[idx].size() > 2)
			return dis;
		else if (idx != R && V[idx].size() == 1)
			return dis;
	} else {
		L = max(L, dis);
	}
	int ret = 0;
	visit[idx] = true;
	for (auto [d, n] : V[idx]) {
		if (visit[n]) continue;
		ret += dfs(n, dis + d, flag);
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> R;
	for (int i = 0; i < N - 1; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		V[a].push_back({d, b});
		V[b].push_back({d, a});
	}
	cout << dfs(R, 0, false) << ' ';
	dfs(G, 0, true);
	cout << L << '\n';
	return 0;
}