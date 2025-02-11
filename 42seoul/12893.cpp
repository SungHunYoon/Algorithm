#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> V[2001];
int D[2001];

bool dfs(int idx, int color) {
	D[idx] = color;
	for (auto v : V[idx]) {
		if (D[v] == color)
			return false;
		else if (D[v])
			continue;
		if (!dfs(v, (color == 1 ? 2 : 1)))
			return false;
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		if (D[i]) continue;
		if (!dfs(i, 1)) {
			cout << "0\n";
			return 0;
		}
	}
	cout << "1\n";
	return 0;
} 