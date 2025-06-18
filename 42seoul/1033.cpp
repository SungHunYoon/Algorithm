#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N;
vector<ii> V[11];
int D[11];

void dfs(int idx, vector<bool> &visited, int value) {
	for (auto [v, d] : V[idx]) {
		if (visited[v]) continue;
		visited[v] = true;
		D[v] *= value;
		dfs(v, visited, value);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b, p, q;
		cin >> a >> b >> p >> q;
		int g = gcd(p, q);
		V[a].push_back({b, q / g});
		V[b].push_back({a, p / g});
	}
	fill(D, D + N + 1, 1);
	for (int i = 0; i < N; i++) {
		vector<bool> visited(N + 1);
		visited[i] = true;
		for (auto [v, d] : V[i]) {
			visited[v] = true;
			D[v] *= d;
			dfs(v, visited, d);
		}
	}
	int g = D[0];
	for (int i = 1; i < N; i++)
		g = gcd(g, D[i]);
	for (int i = 0; i < N; i++)
		cout << D[i] / g << ' ';
	cout << '\n';
	return 0;
}