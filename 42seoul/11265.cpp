#include <iostream>

using namespace std;

int N, M;
int A[501][501];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (A[a][b] <= c)
			cout << "Enjoy other party\n";
		else
			cout << "Stay here\n";
	}
	return 0;
}