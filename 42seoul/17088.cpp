#include <iostream>

using namespace std;

int N;
int B[100001];
int dx[] = {0, -1, 1};
int dc[] = {0, 1, 1};

int dfs(int idx, int prev, int d, int cnt) {
	if (idx > N)
		return cnt;
	int ret = 1e9;
	for (int i = 0; i < 3; i++) {
		int cVal = B[idx] - dx[i];
		int diff = cVal - prev;
		if (diff != d) continue;
		ret = min(ret, dfs(idx + 1, cVal, d, cnt + dc[i]));
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> B[i];
	if (N == 1) {
		cout << "0\n";
		return 0;
	}
	int answer = 1e9;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int fVal = B[1] - dx[j];
			int sVal = B[2] - dx[i];
			int ret = dfs(3, sVal, sVal - fVal, dc[i] + dc[j]);
			answer = min(answer, ret);
		}
	}
	cout << (answer == 1e9 ? -1 : answer) << '\n';
	return 0;
}