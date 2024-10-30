#include <iostream>

using namespace std;

int N, K;
int I[1001], T[1001];
int D[10001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 1; i <= K; i++)
		cin >> I[i] >> T[i];
	for (int i = 1; i <= K; i++)
		for (int j = N; j >= T[i]; j--)
			D[j] = max(D[j], D[j - T[i]] + I[i]);
	cout << D[N] << '\n';
	return 0;
}