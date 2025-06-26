#include <iostream>

using namespace std;

int N, K;
int A[101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int cnt = 0;
	int *minP = A;
	while (1) {
		while (minP != A + N && *minP == 1e9)
			minP++;
		if (minP == A + N) break;
		cnt++;
		int v = 0;
		while (minP != A + N) {
			if (*minP != 1e9 && v < *minP) {
				v = *minP;
				*minP = 1e9;
			}
			minP++;
		}
		minP = A;
	}
	cout << (cnt <= K ? "YES\n" : "NO\n");
	return 0;
}