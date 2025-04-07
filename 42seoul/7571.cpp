#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int X[100001], Y[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> X[i] >> Y[i];
	}
	sort(X, X + M);
	sort(Y, Y + M);
	int answer = 0;
	for (int i = 0; i < M; i++)
		answer += abs(X[M / 2] - X[i]) + abs(Y[M / 2] - Y[i]);
	cout << answer << '\n';
	return 0;
}