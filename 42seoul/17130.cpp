#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
char A[1001][1001];
int D[1002][1002];
int dx[] = {-1, 0, 1};
int dy[] = {-1, -1, -1};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	fill(&D[0][0], &D[1002][0], -1);
	int sy;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
			if (A[i][j] == 'R') {
				D[i][j] = 0;
				sy = j;
			}
		}
	}
	int answer = -1;
	for (int j = sy + 1; j <= M; j++) {
		for (int i = 1; i <= N; i++) {
			if (A[i][j] == '#') continue;
			for (int k = 0; k < 3; k++) {
				int px = i + dx[k];
				int py = j + dy[k];
				D[i][j] = max(D[i][j], D[px][py]);
			}
			if (A[i][j] == 'O') {
				answer = max(answer, D[i][j]);
			}
			if (A[i][j] != 'C' || D[i][j] == -1) continue;
			D[i][j]++;
		}
	}
	cout << answer << '\n';
	return 0;
}