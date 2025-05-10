#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M, X, Y;
vector<ii> V[1001];
int D[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> X >> Y;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		V[a].push_back({c, b});
		V[b].push_back({c, a});
	}
	fill(D, D + N, 1e9);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({D[Y] = 0, Y});
	while (!pq.empty()) {
		auto [d, n] = pq.top(); pq.pop();
		if (D[n] < d) continue;
		for (auto [nD, nN] : V[n]) {
			if (d + nD >= D[nN]) continue;
			pq.push({D[nN] = d + nD, nN});
		}
	}
	sort(D, D + N);
	if (*max_element(D, D + N) * 2 > X) {
		cout << "-1\n";
		return 0;
	}
	int answer = 0, value = 0, idx = 0;
	while (idx < N) {
		while (idx < N && (value + D[idx]) * 2 <= X) {
			value += D[idx];
			idx++;
		}
		answer++;
		value = 0;
	}
	cout << answer << '\n';
	return 0;
}