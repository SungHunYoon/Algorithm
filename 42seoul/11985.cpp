#include <iostream>

using namespace std;

int N, M, K;
int A[20001];
long D[20001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	D[1] = K;
	for (int i = 2; i <= N; i++) {
		D[i] = D[i - 1] + K;
		int minV = A[i], maxV = A[i];
		for (long j = 1; j < M && j < i; j++) {
			minV = min(minV, A[i - j]);
			maxV = max(maxV, A[i - j]);
			D[i] = min(D[i], D[i - j - 1] + (long)K + (j + 1) * (maxV - minV));
		}
	}
	cout << D[N] << '\n';
	return 0;
}