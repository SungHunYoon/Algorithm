#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[1001];
int D[7];
int T[7];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		A[i] %= 7;
	}
	for (int i = 1; i <= N; i++) {
		copy(D, D + 7, T);
		for (int j = 0; j < 7; j++) {
			int day = (j - A[i] + 7) % 7;
			if (!T[day]) continue;
 			D[j] = 1;
		}
		D[A[i]] = 1;
	}
	cout << (D[4] ? "YES" : "NO") << '\n';
	return 0;
}