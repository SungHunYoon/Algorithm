#include <iostream>

using namespace std;

int N, M;
long P[51][51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char ch;
			cin >> ch;
			P[i][j] = P[i][j - 1] + (ch - '0');
		}
		for (int j = 1; j <= M; j++) {
			P[i][j] += P[i - 1][j];
		}
	}

	auto rectSum = [&](int r1, int c1, int r2, int c2) -> long {
		return P[r2][c2] - P[r1 - 1][c2] - P[r2][c1 - 1] + P[r1 - 1][c1 - 1];
	};

	long ans = 0;

	// 1) 세로 3분할
	for (int c1 = 1; c1 <= M - 2; c1++) {
		for (int c2 = c1 + 1; c2 <= M - 1; c2++) {
			long a = rectSum(1, 1, N, c1);
			long b = rectSum(1, c1 + 1, N, c2);
			long c = rectSum(1, c2 + 1, N, M);
			ans = max(ans, a * b * c);
		}
	}

	// 2) 가로 3분할
	for (int r1 = 1; r1 <= N - 2; r1++) {
		for (int r2 = r1 + 1; r2 <= N - 1; r2++) {
			long a = rectSum(1, 1, r1, M);
			long b = rectSum(r1 + 1, 1, r2, M);
			long c = rectSum(r2 + 1, 1, N, M);
			ans = max(ans, a * b * c);
		}
	}

	// 3) 좌 전체 + 우를 상/하로 분할
	for (int c = 1; c <= M - 1; c++) {
		long leftAll = rectSum(1, 1, N, c);
		for (int r = 1; r <= N - 1; r++) {
			long upRight   = rectSum(1, c + 1, r, M);
			long downRight = rectSum(r + 1, c + 1, N, M);
			ans = max(ans, leftAll * upRight * downRight);
		}
	}

	// 4) 우 전체 + 좌를 상/하로 분할
	for (int c = 1; c <= M - 1; c++) {
		long rightAll = rectSum(1, c + 1, N, M);
		for (int r = 1; r <= N - 1; r++) {
			long upLeft   = rectSum(1, 1, r, c);
			long downLeft = rectSum(r + 1, 1, N, c);
			ans = max(ans, rightAll * upLeft * downLeft);
		}
	}

	// 5) 상 전체 + 하를 좌/우로 분할
	for (int r = 1; r <= N - 1; r++) {
		long topAll = rectSum(1, 1, r, M);
		for (int c = 1; c <= M - 1; c++) {
			long bottomLeft  = rectSum(r + 1, 1, N, c);
			long bottomRight = rectSum(r + 1, c + 1, N, M);
			ans = max(ans, topAll * bottomLeft * bottomRight);
		}
	}

	// 6) 하 전체 + 상을 좌/우로 분할
	for (int r = 1; r <= N - 1; r++) {
		long bottomAll = rectSum(r + 1, 1, N, M);
		for (int c = 1; c <= M - 1; c++) {
			long topLeft  = rectSum(1, 1, r, c);
			long topRight = rectSum(1, c + 1, r, M);
			ans = max(ans, bottomAll * topLeft * topRight);
		}
	}

	cout << ans << '\n';
	return 0;
}