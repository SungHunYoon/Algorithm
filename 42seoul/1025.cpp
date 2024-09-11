#include <iostream>
#include <cmath>

using namespace std;

int N, M;
int A[9][9];
long answer = -1;

void dfs(long value, int x, int y, int r, int c) {
	if (0 > x || x >= M || 0 > y || y >= N) {
		return;
	}
	value = value * 10 + A[y][x];
	if (value == pow((long)sqrt(value), 2))
		answer = max(answer, value);
	dfs(value, x + c, y + r, r, c);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
			A[i][j] = s[j] - '0';
	}
	for (int k = 0; k < N; k++) {
		for (int l = 0; l < M; l++) {
			for (int i = -N; i < N; i++) {
				for (int j = -M; j < M; j++) {
					if (!(i == 0 && j == 0)) {
						dfs(0, l, k, i, j);
					}
				}
			}
		}
	}
	cout << answer << '\n';
	return 0;
}