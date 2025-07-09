#include <iostream>

using namespace std;

#define MOD 100999

int T, N;
int D[2001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	D[0] = 1;
	for (int i = 1; i <= 2000; i++) {
		for (int j = 2000; j >= i; j--) {
			D[j] = (D[j] + D[j - i]) % MOD;
		}
	}
	while (T--) {
		cin >> N;
		cout << D[N] << '\n';
	}

	return 0;
}