#include <iostream>

using namespace std;

int T, N;
char A[2][102];
int dx[] = {-1, 0, 1};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> A[i][j];
				if (i == 0) {
					A[i][j] -= '0';
				}
			}
		}
		int answer = 0;
		for (int i = 1; i <= N; i++) {
			if (A[1][i] == '*') {
				for (int j = 0; j < 3; j++) {
					int nx = i + dx[j];
					A[0][nx]--;
				}
				answer++;
			}
		}
		for (int i = 1; i <= N; i++) {
			if (A[1][i] == '#') {
				bool isPossible = true;
				for (int j = 0; j < 3; j++) {
					int nx = i + dx[j];
					if (1 > nx || nx > N) continue;
					if (A[0][nx] == 0) {
						isPossible = false;
						break;
					}
				}
				if (!isPossible) continue;
				for (int j = 0; j < 3; j++) {
					int nx = i + dx[j];
					A[0][nx]--;
				}
				answer++;
			}
		}
		cout << answer << '\n';
	}

	return 0;
}