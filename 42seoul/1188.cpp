#include <iostream>
#include <numeric>

using namespace std;

int N, M;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	if (N % M == 0)
		cout << "0\n";
	else
		cout << M - gcd(N, M) << '\n';
	return 0;
}