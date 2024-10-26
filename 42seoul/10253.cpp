#include <iostream>
#include <numeric>
#include <climits>

using namespace std;

long T, A, B;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> A >> B;
		for (long i = 2; A > 1; i++) {
			long l = lcm(B, i);
			if (A * (l / B) >= l / i) {
				A = ((A * (l / B)) - (l / i));
				B = l;
				long g = gcd(A, B);
				A /= g;
				B /= g;
			}
		}
		cout << B << '\n';
	}
	return 0;
}