#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int A[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sort(A, A + N);
	int start = 0, end = 1;
	int answer = 2e9 + 1;
	while (end < N) {
		int check = A[end] - A[start];
		if (check >= M) {
			answer = min(answer, check);
			start++;
		} else
			end++;
	}
	cout << answer << '\n';
	return 0;
}