#include <iostream>

using namespace std;

int N;
string S;
char Q[] = {'B', 'L', 'D'};
int D[3][1501][1501];

int dfs(int idx, int f, int r, int cnt) {
	if (f > r) {
		return cnt;
	}
	if (D[idx % 3][f][r]) {
		return D[idx % 3][f][r];
	}
	int ret = 0;
	if (S[f] != Q[idx % 3] && S[r] != Q[idx % 3]) {
		return cnt;
	}
	if (S[f] == Q[idx % 3]) {
		ret = max(ret, dfs((idx + 1) % 3, f + 1, r, cnt + 1));
	}
	if (S[r] == Q[idx % 3]) {
		ret = max(ret, dfs((idx + 1) % 3, f, r - 1, cnt + 1));
	}
	return D[idx % 3][f][r] = ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> S;
	cout << dfs(0, 0, S.size() - 1, 0) << '\n';
	return 0;
}