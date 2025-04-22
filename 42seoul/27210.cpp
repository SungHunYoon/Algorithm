#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[100001];
int D[2][100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		if (A[i] == 1) {
			D[0][i] = D[0][i - 1] + 1;
			D[1][i] = D[1][i - 1] - 1;
			D[1][i] = D[1][i] < 0 ? 0 : D[1][i];
		} else {
			D[1][i] = D[1][i - 1] + 1;
			D[0][i] = D[0][i - 1] - 1;
			D[0][i] = D[0][i] < 0 ? 0 : D[0][i];
		}
		answer = max({answer, D[0][i], D[1][i]});
	}
	cout << answer << '\n';
	return 0;
}