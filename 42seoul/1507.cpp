#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[21][21];
bool D[21][21];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (k == i || k == j) continue;
				if (A[i][j] > A[i][k] + A[k][j]) {
					cout << "-1\n";
					return 0;
				}
				if (A[i][j] == A[i][k] + A[j][k]) {
					D[i][j] = 1;
				}
			}
		}
	}
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (D[i][j]) continue;
			answer += A[i][j];
		}
	}
	cout << answer << '\n';
	return 0;
}