#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[500001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	sort(A + 1, A + N + 1);
	int x = 0, y = 1e9;
	for (int i = 2; i < N; i += 2) {
		x = x + A[i] - A[i - 1];
		y = min(x, y) + A[i + 1] - A[i];
	}
	cout << y << '\n';
	return 0;
}