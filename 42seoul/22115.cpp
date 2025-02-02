#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int A[101];
int D[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	fill(D, D + K + 1, 1e9);
	D[0] = 0;
	for (int i = 1; i <= N; i++)
		for (int j = K; j >= A[i]; j--)
			D[j] = min(D[j], D[j - A[i]] + 1);
	cout << (D[K] >= 1e9 ? -1 : D[K]) << '\n';

	return 0;
}