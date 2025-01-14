#include <iostream>

using namespace std;

int N;
int A[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	int s = 0, e = N - 1, answer = 0;
	while (s < e) {
		answer = max(answer, (e - s - 1) * min(A[s], A[e]));
		if (A[s] < A[e])
			s++;
		else
			e--;
	}
	cout << answer << '\n';
	return 0;
}