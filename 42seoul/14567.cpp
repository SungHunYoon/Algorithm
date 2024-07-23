#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, A, B;
vector<int> V[1001];
int D[1001];
int answer[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		V[A].push_back(B);
		D[B]++;
	}
	queue<int> q;
	int G = 1;
	for (int i = 1; i <= N; i++) {
		if (D[i] == 0) {
			q.push(i);
			answer[i] = G;
		}
	}
	G++;
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int p = q.front(); q.pop();
			for (int j = 0; j < V[p].size(); j++) {
				D[V[p][j]]--;
				if (D[V[p][j]] == 0) {
					q.push(V[p][j]);
					answer[V[p][j]] = G;
				}
			}
		}
		G++;
	}
	for (int i = 1; i <= N; i++)
		cout << answer[i] << ' ';
	cout << '\n';
	return 0;
}