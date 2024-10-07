#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int T, N, M, O, S, G, H, A, B, D, X;
vector<ii> V[2001];
int dis[2][2001];

void dijkstra(int idx, int num) {
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	fill(dis[num], dis[num] + N + 1, 1e9);
	dis[num][idx] = 0;
	pq.push({0, idx});
	while (!pq.empty()) {
		auto [d, n] = pq.top(); pq.pop();
		if (dis[num][n] < d) continue;
		for (auto [nD, nN] : V[n]) {
			if (d + nD < dis[num][nN])
				pq.push({dis[num][nN] = d + nD, nN});
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> N >> M >> O >> S >> G >> H; 
		int ghD = 1e9;
		for (int i = 1; i <= N; i++)
			V[i].clear();
		for (int i = 0; i < M; i++) {
			cin >> A >> B >> D;
			V[A].push_back({D, B});
			V[B].push_back({D, A});
			if ((A == G && B == H) ||
				(B == G && A == H))
				ghD = min(ghD, D);
		}
		dijkstra(S, 0);
		vector<int> answer;
		for (int i = 0; i < O; i++) {
			cin >> X;
			dijkstra(X, 1);
			int tmp = dis[0][G] + dis[1][H] + ghD;
			int tmp2 = dis[0][H] + dis[1][G] + ghD;
			if (tmp == dis[0][X] || tmp2 == dis[0][X])
				answer.push_back(X);
		}
		sort(answer.begin(), answer.end());
		for (auto a : answer)
			cout << a << ' ';
		cout << '\n';
	}

	return 0;
}