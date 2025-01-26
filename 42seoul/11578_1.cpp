#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, O, P;
vector<int> T[11];
int V[11];

int dfs(int idx, int cnt) {
	int ret = 1e9;
	if (count(V + 1, V + N + 1, 0) == 0)
		return cnt;
	if (idx > M)
		return ret;
	ret = min(ret, dfs(idx + 1, cnt));
	for (auto v : T[idx])
		V[v]++;
	ret = min(ret, dfs(idx + 1, cnt + 1));
	for (auto v : T[idx])
		V[v]--;
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> O;
		for (int j = 0; j < O; j++) {
			cin >> P;
			T[i].push_back(P);
		}
	}
	int answer = dfs(1, 0);
	cout << (answer == 1e9 ? -1 : answer) << '\n';
	return 0;
}