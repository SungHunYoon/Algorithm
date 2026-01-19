#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[100001];

// 3(|b - (a + b + c) / 3|)
// 3b - (a + b + c)
// a + b + c - 3b
// a - 2b + c

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	sort(A + 1, A + N + 1);
	long answer = 0;
	for (int i = 2; i <= N - 1; i++) {
		answer = max(answer, abs(A[1] - 2L * A[i] + A[i + 1]));
		answer = max(answer, abs(A[i - 1] - 2L * A[i] + A[N]));
	}
	cout << answer << '\n';
	return 0;
}