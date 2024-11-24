#include <iostream>

using namespace std;

int N;
int A[1001];
int T[1001][1001];
int D[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	for (int i = 1; i <= N; i++) {
		int maxValue = -1, minValue = 1e9;
		for (int j = i; j <= N; j++) {
			if (maxValue < A[j]) maxValue = A[j];
			if (minValue > A[j]) minValue = A[j];
			T[i][j] = maxValue - minValue;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			D[i] = max(D[i], D[j] + T[j + 1][i]);
		}
		D[i] = max(D[i], max(T[1][i], D[i - 1]));
	}
	cout << D[N] << '\n';
	return 0;
}