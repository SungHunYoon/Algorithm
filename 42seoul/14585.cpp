#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int A[302][302];
int D[302][302];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		A[x + 1][y + 1] = 1;
	}
	for (int i = 1; i <= 301; i++) {
		for (int j = 1; j <= 301; j++) {
			D[i][j] = max({D[i - 1][j], D[i][j - 1]});
			if (A[i][j]) {
				int candy = M - (i + j - 2);
				D[i][j] += candy > 0 ? candy : 0;
			}
		}
	}
	cout << D[301][301] << '\n';
	return 0;
}