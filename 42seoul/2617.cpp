#include <iostream>
#include <algorithm>

using namespace std;

int N, M, A, B;
int G[101][101];
int L[101][101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)  {
				G[i][j] = 0;
				L[i][j] = 0;
			} else {
				G[i][j] = 1e9;
				L[i][j] = 1e9;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		G[A][B] = 1;
		L[B][A] = 1;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
				L[i][j] = min(L[i][j], L[i][k] + L[k][j]);
			}
		}
	}
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		if (count(G[i], G[i] + N + 1, 1e9) < N / 2)
			answer++;
		if (count(L[i], L[i] + N + 1, 1e9) < N / 2)
			answer++;
	}
	cout << answer << '\n';
	return 0;
}