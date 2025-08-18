#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M, X, Y, K;
int inDegree[101];
vector<ii> V[101];
int D[101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> X >> Y >> K;
		V[X].push_back({Y, K});
		inDegree[Y]++;
	}
	queue<int> q;
	q.push(N);
	while (!q.empty()) {
		int n = q.front(); q.pop();
		for (auto [nN, nC] : V[n]) {
			if (--inDegree[nN] == 0) {
				q.push(nN);
			}
			if (D[n] == 0) {
				D[nN] += nC;
			} else {
				D[nN] += D[n] * nC;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (V[i].size()) continue;
		cout << i << " " << D[i] << '\n';
	}
	return 0;
}