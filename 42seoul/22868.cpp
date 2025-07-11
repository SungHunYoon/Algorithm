#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M, S, E;
vector<int> V[10001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	cin >> S >> E;
	for (int i = 1; i <= N; i++) {
		sort(V[i].begin(), V[i].end());
	}
	queue<ii> q;
	vector<int> visited(N + 1, -1);
	visited[S] = 0;
	q.push({S, 0});
	int cnt = 0, answer = 0;
	while (!q.empty()) {
		auto [n, d] = q.front(); q.pop();
		if (n == E) {
			answer += d;
			break;
		}
		for (auto v : V[n]) {
			if (visited[v] >= 0) continue;
			visited[v] = n;
			q.push({v, d + 1});
		}
	}
	vector<int> visited2(N + 1, -1);
	int T = E;
	while (visited[T]) {
		visited2[visited[T]] = 0;
		T = visited[T];
	}
	visited2[S] = -1;
	queue<ii> q2;
	visited2[E] = 0;
	q2.push({E, 0});
	while (!q2.empty()) {
		auto [n, d] = q2.front(); q2.pop();
		if (n == S) {
			answer += d;
			break;
		}
		for (auto v : V[n]) {
			if (visited2[v] >= 0) continue;
			visited2[v] = true;
			q2.push({v, d + 1});
		}
	}
	cout << answer << '\n';
	return 0;
}