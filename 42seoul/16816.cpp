#include <iostream>

using namespace std;

int S, T, D;
int A[100001];
long P[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S >> T >> D;
	long answer = 1e18;
	for (int i = 1; i <= D; i++) {
		cin >> A[i];
		P[i] = P[i - 1] + A[i];
		if (S + P[i] <= T) {
			answer = min(answer, (long)i);
		}
	}
	if (P[D] < 0) {
		for (int i = 1; i <= D; i++) {
			if (P[i] >= 0) continue;
			long cnt = 1;
			while (S + (cnt * P[D] + P[i]) > T) {
				cnt++;
			}
			cnt *= D;
			cnt += i;
			answer = min(answer, cnt);
		}
	}
	cout << (answer == 1e18 ? -1 : answer) << '\n';
	return 0;
}