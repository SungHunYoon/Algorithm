#include <iostream>

using namespace std;

int N;
int A[50001];
int P[50001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		P[i] = P[i - 1] + A[i];
	}
	int answer = 0;
	int s = 1, e = 2;
	while (s < e && e <= N) {
		int c = P[e] - P[s - 1] - A[e];
		int cc = P[N] - c;
		answer = max(answer, min(c, cc));
		if (c >= cc)
			s++;
		else
			e++;
	}
	cout << answer << '\n';
	return 0;
}