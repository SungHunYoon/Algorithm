#include <iostream>
#include <cmath>

using namespace std;

long S, N, K, R1, R2, C1, C2;
long A[51][51];

bool dfs(long r, long c, long idx, long k) {
	if (idx <= 1)
		return false;
	long m = idx / N;
	if (((idx - k) / 2) <= r && r < ((idx - k) / 2) + k &&
		((idx - k) / 2) <= c && c < ((idx - k) / 2) + k)
			return true;
	if (dfs(r % m, c % m, m, k / N))
		return true;
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S >> N >> K >> R1 >> R2 >> C1 >> C2;
	long m = pow(N, S);
	long k = K * pow(N, S - 1);
	for (int i = R1; i <= R2; i++) {
		for (int j = C1; j <= C2; j++)
			cout << dfs(i, j, m, k);
		cout << '\n';
	}
	return 0;
}