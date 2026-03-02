#include <iostream>
#include <numeric>

using namespace std;

int N;
int A[101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	int maxV = A[1], g = A[1];
	for (int i = 2; i <= N; i++) {
		maxV = max(maxV, A[i]);
		g = gcd(g, A[i]);
	}
	cout << ((maxV / g - N) % 2 ? "Alice\n" : "Bob\n");
	return 0;
}