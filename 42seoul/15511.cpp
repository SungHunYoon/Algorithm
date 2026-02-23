#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M;
int D[1000001];
vector<int> V[1000001];

bool bfs(int idx) {
	queue<ii> q;
	q.push({idx, D[idx] = 1});
	while (!q.empty()) {
		auto [n, c] = q.front(); q.pop();
		for (auto nN : V[n]) {
			int nC = (c == 1 ? 2 : 1); 
			if (D[nN]) {
				if (D[nN] == nC) continue;
				if (D[nN] != nC) return false;
			} else {
				q.push({nN, D[nN] = nC});
			}
		}
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		if (D[i]) continue;
		if (!bfs(i)) {
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}
	cout << "POSSIBLE\n";
	return 0;
}