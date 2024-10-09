#include <iostream>
#include <algorithm>

using namespace std;

int N, M, X;
int A[31];
int D[31][40001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	cin >> M;
	for (int i = 1; i <= N; i++) {
		D[i][A[i]] = 1;
		for (int j = 1; j <= 40000; j++) {
			if (j >= A[i])
				D[i][j] = max(D[i][j], D[i - 1][j - A[i]]);
			if (D[i - 1][j]) {
				D[i][j] = max(D[i][j], D[i - 1][j]);
				D[i][abs(j - A[i])] = max(D[i][abs(j - A[i])], D[i - 1][j]);
			}
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> X;
		cout << (D[N][X] ? "Y " : "N ");
	}
	cout << '\n';
	return 0;
}