#include <iostream>

using namespace std;

int N, I, M;
int X[101], Y[101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> I >> M;
	for (int i = 0; i < M; i++) {
		cin >> X[i] >> Y[i];
	}
	int answer = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 1; j < I / 2; j++) {
			int x = j, y = I / 2 - j;
			for (int k = X[i]; k <= X[i] + x; k++) {
				for (int l = Y[i]; l <= Y[i] + y; l++) {
					int dX = k - X[i], dY = l - Y[i];
					int cnt = 0;
					for (int m = 0; m < M; m++) {
						if (X[i] - dX > X[m] || X[i] + x - dX < X[m] || Y[i] - dY > Y[m] || Y[i] + y - dY < Y[m]) continue;
						cnt++;
					}
					answer = max(answer, cnt);
				}
			}
		}
	}
	cout << answer << '\n';
	return 0;
}