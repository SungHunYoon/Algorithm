#include <iostream>
#include <numeric>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
using iii = tuple<int, int, int>;

int N, M, K;
int A[51][51];
iii R[6];
bool visit[6];
int answer = 1e9;

void rotateOperate(vector<vector<int>> &B, int idx) {
	auto [r, c, s] = R[idx];

	for (int i = 1; i <= s; i++) {
		int tmp = B[r - i][c - i];
		for (int j = c - i + 1; j <= c + i; j++)
			swap(tmp, B[r - i][j]);
		for (int j = r - i + 1; j <= r + i; j++)
			swap(tmp, B[j][c + i]);
		for (int j = c + i - 1; j >= c - i; j--)
			swap(tmp, B[r + i][j]);
		for (int j = r + i - 1; j >= r - i; j--)
			swap(tmp, B[j][c - i]);
	}
}

void reRotateOperate(vector<vector<int>> &B, int idx) {
	auto [r, c, s] = R[idx];

	for (int i = 1; i <= s; i++) {
		int tmp = B[r - i][c - i];
		for (int j = r - i + 1; j <= r + i; j++)
			swap(tmp, B[j][c - i]);
		for (int j = c - i + 1; j <= c + i; j++)
			swap(tmp, B[r + i][j]);
		for (int j = r + i - 1; j >= r - i; j--)
			swap(tmp, B[j][c + i]);
		for (int j = c + i - 1; j >= c - i; j--)
			swap(tmp, B[r - i][j]);
	}
}

void dfs(vector<vector<int>> &B, int idx) {
	if (idx >= K) {
		for (int i = 1; i <= N; i++)
			answer = min(answer, accumulate(B[i].begin(), B[i].end(), 0));
		return;
	}

	for (int i = 0; i < K; i++) {
		if (!visit[i]) {
			visit[i] = true;
			rotateOperate(B, i);
			dfs(B, idx + 1);
			reRotateOperate(B, i);
			visit[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> A[i][j];
	for (int i = 0; i < K; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		R[i] = {r, c, s};
	}
	vector<vector<int>> B(N + 1, vector<int>(M + 1, 0));
	for (int j = 1; j <= N; j++)
		for (int k = 1; k <= M; k++)
			B[j][k] = A[j][k];
	dfs(B, 0);
	cout << answer << '\n';
	return 0;
}