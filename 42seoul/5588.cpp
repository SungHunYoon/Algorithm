#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int M, N;
set<ii> A;
int X[1001], Y[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M;
	int sX = -1, sY = -1;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		if (sX == -1) {
			sX = x;
			sY = y;
		}
		A.insert({x - sX, y - sY});
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i];
	}
	for (int i = 0; i < N; i++) {
		int cnt = 0, dX, dY;
		for (int j = 0; j < N; j++) {
			if (A.find({X[j] - X[i], Y[j] - Y[i]}) != A.end()) {
				cnt++;
			}
		}
		if (cnt == A.size()) {
			cout << X[i] - sX << " " << Y[i] - sY << '\n';
		}
	}

	return 0;
}