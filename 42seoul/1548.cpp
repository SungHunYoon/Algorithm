#include <iostream>
#include <algorithm>

using namespace std;
int N;
int A[51];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);
	int answer = N > 2 ? 2 : N;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int cnt = 2;
			for (int k = j + 1; k < N; k++) {
				if (A[i] + A[j] <= A[k]) break;
				cnt++;
			}
			answer = max(answer, cnt);
		}
	}
	cout << answer << '\n';
	return 0;
}