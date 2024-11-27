#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[51];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	if (N > 1 && count(A, A + N, A[0]) == N)
		cout << A[0] << '\n';
	else if (N <= 2)
		cout << "A\n";
	else {
		int a = (A[1] - A[2]) / ((A[0] - A[1]) == 0 ? 1 : A[0] - A[1]);
		int b = A[1] - (A[0] * a);
		for (int i = 1; i < N; i++) {
			if (A[i - 1] * a + b != A[i]) {
				cout << "B\n";
				return 0;
			}
		}
		cout << A[N - 1] * a + b << '\n';
	}
	return 0;
}