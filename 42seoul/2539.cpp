#include <iostream>
#include <algorithm>

using namespace std;

int R, C, N, M;
int A[1000001];

bool isPossible(int mid) {
	int cnt = 0;
	for (int i = 1; i <= C; i++) {
		if (!A[i]) continue;
		i += mid - 1;
		cnt++;
	}
	if (cnt <= N)
		return true;
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> R >> C >> N >> M;
	int mVal = 0;
	for (int i = 1; i <= M; i++) {
		int x, y;
		cin >> x >> y;
		A[y] = max(A[y], x);
		mVal = max(mVal, A[y]);
	}
	int s = -1, e = 1e9;
	while (s + 1 < e) {
		int mid = (s + e) / 2;
		if (mVal <= mid && isPossible(mid)) {
			e = mid;
		} else {
			s = mid;
		}
	}
	cout << e << '\n';
	return 0;
}