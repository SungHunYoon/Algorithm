#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int N;
int A[21][21];
int visit[21][21];

int calculate(int x, int y, int d1, int d2)
{
	int size[5] = { 0, };

	for (int i = 1; i <= N; i++)
		fill(visit[i], visit[i] + 21, 0);

	for (int i = 0; i <= d1; i++) {
		if (!visit[x + i][y - i]) {
			visit[x + i][y - i] = 5;
			size[4] += A[x + i][y - i];
		}
		if (!visit[x + d2 + i][y + d2 - i]) {
			visit[x + d2 + i][y + d2 - i] = 5;
			size[4] += A[x + d2 + i][y + d2 - i];
		}
	}
	for (int i = 0; i <= d2; i++) {
		if (!visit[x + i][y + i]) {
			visit[x + i][y + i] = 5;
			size[4] += A[x + i][y + i];
		}
		if (!visit[x + d1 + i][y - d1 + i]) {
			visit[x + d1 + i][y - d1 + i] = 5;
			size[4] += A[x + d1 + i][y - d1 + i];
		}
	}
	for (int i = x; i <= x + d1 + d2; i++) {
		int start = -1;
		int end = -1;
		for (int j = 0; j <= N; j++) {
			if (visit[i][j] == 5) {
				if (start == -1)
					start = j;
				else
					end = j;
			}
		}
		for (int j = start; j <= end; j++) {
			if (!visit[i][j]) {
				visit[i][j] = 5;
				size[4] += A[i][j];
			}
		}
	}

	for (int i = 1; i < x + d1; i++) {
		for (int j = 1; j <= y; j++) {
			if (visit[i][j]) break;
			visit[i][j] = 1;
			size[0] += A[i][j];
		}
	}
	for (int i = 1; i <= x + d2; i++) {
		for (int j = N; j >= y + 1; j--) {
			if (visit[i][j]) break;
			visit[i][j] = 2;
			size[1] += A[i][j];
		}
	}
	for (int i = x + d1; i <= N; i++) {
		for (int j = 1; j < y - d1 + d2; j++) {
			if (visit[i][j]) break;
			visit[i][j] = 3;
			size[2] += A[i][j];
		}
	}
	for (int i = x + d2 + 1; i <= N; i++) {
		for (int j = N; j >= y - d1 + d2; j--) {
			if (visit[i][j]) break;
			visit[i][j] = 4;
			size[3] += A[i][j];
		}
	}
	return *max_element(size, size + 5) - *min_element(size, size + 5);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];

	int answer = 1e9;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int d1 = 1; d1 <= N; d1++) {
				for (int d2 = 1; d2 <= N; d2++) {
					if (1 <= i + d1 + d2 && i + d1 + d2 <= N && 1 <= j - d1 && j + d2 <= N)
						answer = min(answer, calculate(i, j, d1, d2));
				}
			}
		}
	}
	cout << answer << '\n';
	return 0;
}