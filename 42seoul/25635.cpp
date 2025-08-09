#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int N;
long A[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	sort(A + 1, A + N + 1, greater<long>());
	long sum = accumulate(A + 2, A + N + 1, 0L);
	cout << (A[1] > sum ? sum + (sum + 1) : A[1] + sum) << '\n';
	return 0;
}