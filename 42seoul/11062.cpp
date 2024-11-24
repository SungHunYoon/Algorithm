#include <iostream>
#include <algorithm>

using namespace std;

int T, N;
int A[1001];
int D[1001][1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) { 
		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> A[i];
		bool turn = true;
		if (N % 2 == 0)
			turn = false;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N - i + 1; j++) {
				int r = j;
				int c = i + j - 1;
				if (turn)
					D[r][c] = max(D[r + 1][c] + A[r], D[r][c - 1] + A[c]);
				else
					D[r][c] = min(D[r + 1][c], D[r][c - 1]);
			}
			turn = !turn;
		}
		cout << D[1][N] << '\n';
		fill(&D[0][0], &D[1001][0], 0);
	}
	return 0;
}
