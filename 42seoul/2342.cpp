#include <iostream>
#include <algorithm>

using namespace std;

int X, N;
int D[100001][5][5];

int measureForce(int idx) {
	int ret = 0;

	if (idx == 0)
		ret = 2;
	else if (idx == 1 || idx == 3) {
		if (X == idx)
			ret = 1;
		else if (X == 2 || X == 4)
			ret = 3;
		else
			ret = 4;
	} else {
		if (X == idx)
			ret = 1;
		else if (X == 1 || X == 3)
			ret = 3;
		else
			ret = 4;
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	fill(&D[0][0][0], &D[100001][0][0], 1e9);
	D[0][0][0] = 0;
	while (cin >> X) {
		if (X == 0)
			break;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (D[N][i][j] != 1e9) {
					int iF = measureForce(i);
					int jF = measureForce(j);
					if (j != X)
						D[N + 1][X][j] = min(D[N + 1][X][j], D[N][i][j] + iF);
					if (i != X)
						D[N + 1][i][X] = min(D[N + 1][i][X], D[N][i][j] + jF);
				}
			}
		}
		N++;
	}
	int answer = 1e9;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			answer = min(answer, D[N][i][j]);
	cout << answer << '\n';
	return 0;
}