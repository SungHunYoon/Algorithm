#include <iostream>

using namespace std;

int N;
int X[100001], Y[100001];
long D[100001][5];
int dx[] = {-1, 1, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0};

int getDistance(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> X[0] >> Y[0];
	for (int i = 1; i <= N; i++)
		cin >> X[i] >> Y[i];
	fill(&D[0][0], &D[N + 1][0], 1e17);
	for (int i = 0; i < 5; i++)
		D[1][i] = getDistance(X[0], Y[0], X[1] + dx[i], Y[1] + dy[i]);
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 5; j++) {
			int cx = X[i] + dx[j];
			int cy = Y[i] + dy[j];
			if (1 > cx || cx > 100000 || 1 > cy || cy > 100000) continue;
			for (int k = 0; k < 5; k++) {
				int px = X[i - 1] + dx[k];
				int py = Y[i - 1] + dy[k];
				if (1 > px || px > 100000 || 1 > py || py > 100000) continue;
				D[i][j] = min(D[i][j], D[i - 1][k] + getDistance(cx, cy, px, py));
			}
		}
	}
	long answer = 1e17;
	for (int i = 0; i < 5; i++)
		answer = min(answer, D[N][i]);
	cout << answer << '\n';
	return 0;
}