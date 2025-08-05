#include <iostream>
#include <algorithm>

using namespace std;

int A, B, C;
int X[1001], Y[1001], Z[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> A >> B >> C;
	for (int i = 1; i <= A; i++) {
		cin >> X[i];
	}
	for (int i = 1; i <= B; i++) {
		cin >> Y[i];
	}
	for (int i = 1; i <= C; i++) {
		cin >> Z[i];
	}
	sort(X + 1, X + A + 1);
	sort(Y + 1, Y + B + 1);
	sort(Z + 1, Z + C + 1);
	int answer = 1e9, xIdx = 1, yIdx = 1, zIdx = 1;
	while (xIdx <= A && yIdx <= B && zIdx <= C) {
		int maxV = max({X[xIdx], Y[yIdx], Z[zIdx]});
		int minV = min({X[xIdx], Y[yIdx], Z[zIdx]});
		answer = min(answer, abs(maxV - minV));
		if (minV == X[xIdx]) xIdx++;
		else if (minV == Y[yIdx]) yIdx++;
		else zIdx++;
	}
	cout << answer << '\n';
	return 0;
}