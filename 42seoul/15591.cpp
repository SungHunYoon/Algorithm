#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using li = pair<long, int>;

int N, Q, A, B, C;
vector<li> V[5001];
long D[5001];

void bfs(int idx) {
	fill(D, D + N + 1, 1e18);
	queue<li> q;
	q.push({0, idx});
	while (!q.empty()) {
		auto [r, p] = q.front(); q.pop();
		D[p] = r;
		for (auto [nR, nP] : V[p]) {
			if (D[nP] != 1e18) continue;
			if (r == 0)
				q.push({nR, nP});
			else
				q.push({min(r, nR), nP});
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> Q;
	for (int i = 0; i < N - 1; i++) {
		cin >> A >> B >> C;
		V[A].push_back({C, B});
		V[B].push_back({C, A});
	}
	while (Q--) {
		cin >> A >> B;
		bfs(B);
		int answer = 0;
		for (int i = 1; i <= N; i++) {
			if (i == B) continue;
			if (D[i] >= A) answer++;
		}
		cout << answer << '\n';
	}
	return 0;
}