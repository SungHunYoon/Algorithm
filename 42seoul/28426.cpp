#include <iostream>
#include <vector>

using namespace std;

int N;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vector<int> A(N);
	A[0] = 3;
	long sum = A[0];
	for (int i = 1, j = 2; i < N; i++, j += 2) {
		A[i] = j;
		sum += j;
	}
	if (sum % 3 != 0) {
		long add = 2;
		while ((sum + add) % 3 != 0) {
			add += 2;
		}
		A[N - 1] += add;
	}
	for (auto a : A) {
		cout << a << ' ';
	}
	cout << '\n';
	return 0;
}
