#include <iostream>
#include <vector>

using namespace std;

int N, W;
vector<int> V[500001];
bool visit[500001];
int cnt;

double dfs(int idx, double water) {
	visit[idx] = true;
	if (idx != 1 && V[idx].size() == 1) {
		cnt++;
		return water;
	}
	double ret = 0;
	double avg = water / (V[idx].size() - (idx == 1 ? 0 : 1));
	for (int i = 0; i < V[idx].size(); i++) {
		if (!visit[V[idx][i]]) ret += dfs(V[idx][i], avg);
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> W;
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		V[u].push_back(v);
		V[v].push_back(u);
	}
	cout.precision(10);
	cout << dfs(1, W) / cnt << '\n';
	return 0;
}