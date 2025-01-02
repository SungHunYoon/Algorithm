#include <iostream>
#include <algorithm>

using namespace std;

int T, N, K;
int A[1000001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> N >> K;
		for (int i = 0; i < N; i++)
			cin >> A[i];
		sort(A, A + N);
		int answer = 0, diff = 1e9;
		int s = 0, e = N - 1;
		while (s < e) {
			int sum = A[s] + A[e];
			if (abs(K - sum) < diff) {
				diff = abs(K - sum);
				answer = 0;
			}
			if (diff == abs(K - sum))
				answer++;
			if (K <= sum) e--;
			else s++;
		}
		cout << answer << '\n';
	}
	return 0;
}