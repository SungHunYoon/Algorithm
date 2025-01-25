#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M, H;
int A[11][11];
vector<ii> P;
bool V[11];

int dfs(int idx, int cnt, int hp) {
	int ret = 0;
	auto [cx, cy] = P[idx];
	for (int i = 0; i < P.size(); i++) {
		if (i == idx || V[i]) continue;
		auto [nx, ny] = P[i];
		int d = abs(cx - nx) + abs(cy - ny);
		if (d > hp) continue;
		if (i == 0)
			ret = max(ret, cnt);
		else {   
			V[i] = true;
			ret = max(ret, dfs(i, cnt + 1, hp - d + H));
			V[i] = false;
		}
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> H;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			if (A[i][j] == 1)
				P.insert(P.begin(), {i, j});
			else if (A[i][j] == 2)
				P.push_back({i, j});
		}
	}
	cout << dfs(0, 0, M) << '\n';
	return 0;
}