#include <iostream>
#include <algorithm>

using namespace std;

int N, C;
int A[5001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> C;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	sort(A + 1, A + N + 1);
	if (binary_search(A + 1, A + N + 1, C)) {
		cout << "1\n";
		return 0;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (A[i] + A[j] == C || binary_search(A + j + 1, A + N + 1, C - (A[i] + A[j]))) {
				cout << "1\n";
				return 0;
			}
		}
	}
	cout << "0\n";
	return 0;
}