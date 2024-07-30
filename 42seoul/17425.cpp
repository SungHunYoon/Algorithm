#include <iostream>

using namespace std;

int T, N;
int A[1000001];
long prefix[1000001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int i = 1; i <= 1000000; i++) {
		for (int j = i; j <= 1000000; j += i)
			A[j] += i;
	}
	for (int i = 1; i <= 1000000; i++)
		prefix[i] = prefix[i - 1] + A[i];
	while (T--) {
		cin >> N;
		cout << prefix[N] << '\n';
	}
	return 0;
}
