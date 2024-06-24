#include <iostream>
#include <cmath>

using namespace std;

long long N, K;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	long long n = 0;
	long long m = 1;
	long long d = 0;
	if (K > 9) {
		while (n + (d * 10 * m) < K) {
			d = d == 0 ? 9 : d * 10;
			n += d * m;
			m++;
		}
	}
	long long p = pow(10, m - 1);
	while (n + m < K) {
		p++;
		n += m;
	}
	if (p > N) {
		cout << "-1\n";
		return 0;
	}
	long long i = 0;
	long long dest = m - (K - n);
	while (i < dest) {
		p /= 10;
		i++;
	}
	cout << p % 10 << '\n';
	return 0;
}