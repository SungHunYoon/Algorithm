#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, X, Y;
int D[3001];
bool visit[2][3001];
vector<int> V[3001];

bool dfs(int idx, int cnt, int s) {
	visit[1][idx] = true;
	for (int i = 0; i < V[idx].size(); i++) {
		if (cnt > 1 && V[idx][i] == s)
			return true;
		if (!visit[1][V[idx][i]]) {
			if (dfs(V[idx][i], cnt + 1, s))
				return true;
		}
	}
	return false;
}

void dfsCnt(int idx, int cnt, int s) {
	visit[1][idx] = true;
	for (int i = 0; i < V[idx].size(); i++) {
		if (visit[0][V[idx][i]]) {
			D[s] = min(D[s], cnt);
			return;
		}
		if (!visit[1][V[idx][i]]) {
			dfsCnt(V[idx][i], cnt + 1, s);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X >> Y;
		V[Y].push_back(X);
		V[X].push_back(Y);
	}
	for (int i = 1; i <= N; i++) {
		fill(visit[1], visit[1] + N + 1, false);
		if (dfs(i, 0, i))
			visit[0][i] = true;
	}
	fill(D, D + N + 1, 1e9);
	for (int i = 1; i <= N; i++) {
		copy(visit[0], visit[0] + N + 1, visit[1]);
		if (visit[1][i]) D[i] = 0;
		else dfsCnt(i, 1, i);
	}
	for (int i = 1; i <= N; i++)
		cout << D[i] << ' ';
	cout << '\n';
	return 0;
}