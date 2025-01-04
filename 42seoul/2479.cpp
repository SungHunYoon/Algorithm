#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, K, S, E;
string A[1001];
vector<ii> V[1001];
int D[1001];
int T[1001];

void dijkstra(int idx) {
	fill(D, D + N + 1, 1e9);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({D[idx] = 0, idx});
	while (!pq.empty()) {
		auto [d, n] = pq.top(); pq.pop();
		if (d > D[n]) continue;
		for (auto [nD, nN] : V[n]) {
			if (d + nD > D[nN]) continue;
			T[nN] = n;
			pq.push({D[nN] = d + nD, nN});
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	cin >> S >> E;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			int diff = 0;
			for (int k = 0; k < K; k++) {
				if (A[i][k] != A[j][k])
					diff++;
			}
			if (diff != 1) continue;
			V[i].push_back({diff, j});
			V[j].push_back({diff, i});
		}
	}
	dijkstra(S);
	if (D[E] == 1e9) {
		cout << "-1\n";
		return 0;
	}
	vector<int> answer;
	answer.push_back(E);
	while (T[E]) {
		answer.push_back(T[E]);
		E = T[E];
	}
	reverse(answer.begin(), answer.end());
	for (auto v : answer)
		cout << v << ' ';
	cout << '\n';
	return 0;
}