#include <iostream>

using namespace std;

long N, M;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> N;
	long X, Y, C;
	if (N >= M) {
		if (M % 2 == 0)
			X = M / 2;
		else
			X = M / 2 + M % 2 + (N - M);
		Y = M / 2 + 1;
		C = M * 2 - 1;
	} else {
		if (N % 2 == 0)
			Y = N / 2 + 1;
		else
			Y = N / 2 + N % 2 + (M - N);
		X = N / 2 + N % 2;
		C = N * 2;
	}
	cout << C - 1 << '\n' << Y << " " << X << '\n';
	return 0;
}