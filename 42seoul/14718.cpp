#include <iostream>

using namespace std;

int N, K;
int S[101], D[101], I[101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> S[i] >> D[i] >> I[i];
	}
	int answer = 1e9;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				int cnt = 0;
				for (int l = 1; l <= N; l++) {
					if (S[i] < S[l]) continue;
					if (D[j] < D[l]) continue;
					if (I[k] < I[l]) continue;
					cnt++;
				}
				if (cnt >= K) {
					answer = min(answer, S[i] + D[j] + I[k]);
				}
			}
		}
	}
	cout << answer << '\n';
	return 0;
}