#include <iostream>
#include <algorithm>

using namespace std;

int T, K, P, N;
pair<int, int> A[101];
int D[101][10001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T >> K;
	for (int i = 1; i <= K; i++)
		cin >> A[i].first >> A[i].second;
	// sort(A + 1, A + K + 1);
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= T; j++)
			D[i][j] += D[i - 1][j];
		for (int j = 1; j <= A[i].second; j++) {
			if (A[i].first * j > T) break;
			for (int k = A[i].first * j + 1; k <= T; k++) {
				if (k > T) break;
				D[i][k] += D[i - 1][k - A[i].first * j];
			}
			D[i][A[i].first * j]++;
		}
	}
	// for (int i = 1; i <= K; i++) {
	// 	for (int j = 1; j <= T; j++)
	// 		cout << D[i][j] << ' ';
	// 	cout << '\n';
	// }
	cout << D[K][T] << '\n';
	return 0;
}