#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int V, E;
vector<int> A[3001];
bool visited[3001];

bool dfs(int idx, int cnt) {
	if (cnt > 2)
		return false;
	visited[idx] = true;
	for (auto a : A[idx]) {
		if (visited[a]) continue;
		if (!dfs(a, cnt + A[idx].size() % 2))
			return false;
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		A[a].push_back(b);
		A[b].push_back(a);
	}
	if (!dfs(1, 0) || accumulate(visited, visited + V + 1, 0) != V) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
	return 0;
}