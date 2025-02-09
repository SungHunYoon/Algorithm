#include <iostream>

using namespace std;

#define MOD 123456789

int N;
int D[40001];
bool T[40001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 2; i <= N; i++) {
		if (T[i]) continue;
		for (int j = i + i; j <= N; j += i)
			T[j] = true;
	}
	D[0] = 1;
	for (int i = 2; i <= N; i++) {
		if (T[i]) continue;
		for (int j = i; j <= N; j++)
			D[j] = ((D[j] + D[j - i]) % MOD);
	}
	cout << D[N] << '\n';
	return 0;
}