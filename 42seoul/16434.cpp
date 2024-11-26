#include <iostream>

using namespace std;

int N, ATK;
int T[123457], A[123457], H[123457];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> ATK;
	for (int i = 1; i <= N; i++)
		cin >> T[i] >> A[i] >> H[i];
	long s = 1, e = 1e18;
	while (s < e) {
		long mid = (s + e) / 2;
		long atk = ATK;
		long curhp = mid;
		for (int i = 1; i <= N; i++) {
			if (T[i] == 1) {
				curhp -= A[i] * ((H[i] / atk) + (H[i] % atk ? 1 : 0) - 1);
			} else {
				atk += A[i];
				curhp += H[i];
				if (curhp > mid)
					curhp = mid;
			}
			if (curhp <= 0) break;
		}
		if (curhp <= 0) {
			s = mid + 1;
		} else {
			e = mid;
		}
	}
	cout << e << '\n';
	return 0;
}

