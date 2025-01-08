#include <iostream>

using namespace std;

int N;
int A[301][301];
int P[301][301];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			P[i][j] = P[i][j - 1] + A[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			P[i][j] += P[i - 1][j]; 
	}
	int answer = -1e9;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (j - i < 0 || k - i < 0) continue;
				int sum = P[j][k] - P[j - i][k] - P[j][k - i] + P[j - i][k - i];
				answer = max(answer, sum);
			}
		}
	}
	cout << answer << '\n';
	return 0;
}