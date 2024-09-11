#include <iostream>

using namespace std;

int N, R;
int D[28];

void recursive(int s, int e, int r, bool f) {
	if (r == 0 || f) {
		if (s == N)
			cout << "m\n";
		else if (s < N && N <= e)
			cout << "o\n";
		return;
	}

	if (s <= N && N <= s + D[r - 1] - 1)
		recursive(s, s + D[r - 1] - 1, r - 1, false);
	if (s + D[r - 1] <= N && N <= s + D[r - 1] + 2 + r)
		recursive(s + D[r - 1], s + D[r - 1] + 2 + r, r - 1, true);
	if (s + D[r - 1] + 3 + r <= N && N <= e)
		recursive(s + D[r - 1] + 3 + r, e, r - 1, false);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	D[0] = 3;
	for (int i = 1; i <= 27; i++) {
		D[i] = D[i - 1] * 2 + (3 + i);
		if (D[i] >= N) {
			R = i;
			break;
		}
	}
	recursive(1, D[R], R, false);
	return 0;
}
