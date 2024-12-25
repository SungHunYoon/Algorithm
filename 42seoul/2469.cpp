#include <iostream>
#include <algorithm>

using namespace std;

int K, N;
char A[1001][26];
int D[1002][26];
int T;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string S;
	cin >> K >> N >> S;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K - 1; j++) {
			cin >> A[i][j];
			if (A[i][j] == '?') T = i;
		}
	}
	for (int i = 0; i < K; i++) {
		D[N + 1][i] = S[i] - 'A';
		D[0][i] = i;
	}
	for (int i = 1; i < T; i++) {
		for (int j = 0; j < K; j++) {
			if (j + 1 <= K - 1 && A[i][j + 1] == '-')
				D[i][j] = D[i - 1][j + 1];
			else if (1 <= j && A[i][j] == '-')
				D[i][j] = D[i - 1][j - 1];
			else
				D[i][j] = D[i - 1][j];
		}
	}
	for (int i = N; i > T; i--) {
		for (int j = 0; j < K; j++) {
			if (j + 1 <= K - 1 && A[i][j + 1] == '-')
				D[i][j] = D[i + 1][j + 1];
			else if (1 <= j && A[i][j] == '-')
				D[i][j] = D[i + 1][j - 1];
			else
				D[i][j] = D[i + 1][j];
		}
	}
	string answer;
	for (int i = 0; i < K; i++) {
		if (D[T - 1][i] != D[T + 1][i]) {
			swap(D[T - 1][i], D[T - 1][i + 1]);
			answer += '-';
		} else {
			answer += '*';
		}
	}
	for (int i = 0; i < K; i++) {
		if (D[T - 1][i] != D[T + 1][i])
			answer = string(K, 'x');
	}
	answer.pop_back();
	cout << answer << '\n';
	return 0;
}