#include <iostream>

using namespace std;

int dx[13][4] = {
	{0, 0, 0, 0},
	{0, 1, 2, 3},
	{0, 0, 1, 1},
	{0, 1, 1, 2},
	{0, 0, 0, 1},
	{0, 1, 2, 2},
	{0, 1, 1, 1},
	{0, 0, 1, 2},
	{0, 0, 0, 1},
	{0, 1, 1, 2},
	{0, 1, 1, 1},
	{0, 1, 1, 2},
	{0, 0, 1, 1},
};

int dy[13][4] = {
	{0, 1, 2, 3},
	{0, 0, 0, 0},
	{0, 1, 1, 2},
	{0, -1, 0, -1},
	{0, 1, 2, 2},
	{0, 0, -1, 0},
	{0, 0, 1, 2},
	{0, 1, 0, 0},
	{0, 1, 2, 1},
	{0, -1, 0, 0},
	{0, -1, 0, 1},
	{0, 0, 1, 0},
	{0, 1, 0, 1},
};

int N;
int A[101][101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int idx = 1;
	while (cin >> N) {
		if (N == 0) break;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++)
				cin >> A[i][j];
		}
		long answer = -1e14;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 0; k < 13; k++) {
					long sum = 0;
					for (int l = 0; l < 4; l++) {
						int nx = i + dx[k][l];
						int ny = j + dy[k][l];
						if (1 > nx || nx > N || 1 > ny || ny > N) {
							sum = -1e14;
							break;
						}
						sum += A[nx][ny];
					}
					answer = max(answer, sum);
				}
			}
		}
		cout << idx << ". " << answer << '\n';
		idx++;
	}
	return 0;
}