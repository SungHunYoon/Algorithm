#include <iostream>
#include <vector>

using namespace std;

int N;
char A[6][6];
int dx[] = {1, 0};
int dy[] = {0, 1};
int minVal = 1e9, maxVal = -1e9;

void dfs(vector<char> &B, int x, int y) {
	if (x == N && y == N) {
		int ret = B[0] - '0';
		for (int i = 1; i < B.size(); i++) {
			if (i % 2) continue;
			if (B[i - 1] == '+') {
				ret += B[i] - '0';
			} else if (B[i - 1] == '*') {
				ret *= B[i] - '0';
			} else {
				ret -= B[i] - '0';
			}
		}
		minVal = min(minVal, ret);
		maxVal = max(maxVal, ret);
		return;
	}
	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx > N || ny > N) continue;
		B.push_back(A[nx][ny]);
		dfs(B, nx, ny);
		B.pop_back();
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	vector<char> B;
	B.push_back(A[1][1]);
	dfs(B, 1, 1);
	cout << maxVal << " " << minVal << '\n';
	return 0;
}