#include <iostream>
#include <algorithm>

using namespace std;

long A, B;

int gcd(int a, int b) {
	int mod;
	while ((mod = a % b)) {
		a = b;
		b = mod;
	}
	return b;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> A >> B;
	long a = 1e9, b = 1e9;
	for (int i = A; i <= B; i += A) {
		long tA = i;
		long tB = B / i * A;
		long tGcd = gcd(tA, tB);
		if (tGcd == A && (tA * tB) / tGcd == B && (tA + tB) < a + b) {
			a = min(tA, tB);
			b = max(tA, tB);
		}
	}
	cout << a << " " << b << '\n';
	return 0;
}
