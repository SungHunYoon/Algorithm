#include <iostream>

using namespace std;

int T, S, F;
int D[32];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> S >> F;
		if (S % 2 == 0 && F % 2 == 0)
			cout << (F ^ ((F - S) / 2 % 2)) << '\n';
		else if (S % 2 == 0 && F % 2 == 1)
			cout << ((F + 1 - S) / 2 % 2) << '\n';
		else if (S % 2 == 1 && F % 2 == 0)
			cout << (S ^ F ^ ((F - S) / 2 % 2)) << '\n';
		else
			cout << (S ^ ((F + 1 - S) / 2 % 2)) << '\n';
	}
	return 0;
}