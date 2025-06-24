#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, N, F;
vector<int> V[901];
int T[901];
bool visited[901];

bool dfs(int std, int idx, int cnt) {
	if (count(T, T + N + 1, 1) < K) {
		return false;
	}
	if (cnt >= K) {
		return true;
	}
	int O[901];
	for (int i = 1; i <= N; i++)
		O[i] = T[i];
	for (int i = idx; i < V[std].size(); i++) {
		if (visited[V[std][i]]) continue;
		for (int j = 0, k = 1; k <= N; k++) {
			if (j < V[V[std][i]].size() && V[V[std][i]][j] == k) {
				T[k] &= 1;
				j++;
			} else {
				T[k] &= 0;
			}
		}
		visited[V[std][i]] = true;
		if (dfs(std, i, cnt + 1)) {
			return true;
		}
		for (int j = 1; j <= N; j++)
			T[j] = O[j];
		visited[V[std][i]] = false;
	}
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> K >> N >> F;
	for (int i = 0; i < F; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		V[i].push_back(i);
		sort(V[i].begin(), V[i].end());
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1, k = 0; j <= N; j++) {
			if (k < V[i].size() && V[i][k] == j) {
				T[j] = 1;
				k++;
			} else {
				T[j] = 0;
			}
		}
		visited[i] = true;
		if (dfs(i, 0, 1)) {
			for (int j = 1, c = 0; j <= N && c < K; j++) {
				if (!T[j]) continue;
				cout << j << '\n';
				c++;
			}
			return 0;
		}
		visited[i] = false;
	}
	cout << "-1\n";
	return 0;
}