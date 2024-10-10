#include <iostream>
#include <algorithm>

using namespace std;

int T, N;
int A[501];
int D[501][501];
int prefix[501];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
			prefix[i] = prefix[i - 1] + A[i];
			fill(D[i], D[i] + 501, 1e9);
			D[i][i] = 0;
		}
		for (int i = 1; i < N; i++)
			for (int j = 1; j < N - i + 1; j++)
				for (int k = j; k <= i + j; k++)
					D[j][i + j] = min(D[j][i + j], D[j][k] + D[k + 1][i + j] + prefix[i + j] - prefix[j - 1]);
		cout << D[1][N] << '\n';
	}
	return 0;
}
