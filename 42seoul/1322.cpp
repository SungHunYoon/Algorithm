#include <iostream>

using namespace std;

long X, Y;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> X >> Y;
	long num = 0, mask = 0;
	for (long i = 1; num <= Y; i <<= 1) {
		if (X & i) continue;
		mask |= i;
		num <<= 1;
		num |= 1;
	}
	long answer = 0;
	for (long i = 1, j = 1; j <= num; i <<= 1) {
		if ((mask & i)) {
			if (Y & j)
				answer |= i;
			j <<= 1;
		}
	}
	cout << answer << '\n';
	return 0;
}