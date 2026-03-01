#include <iostream>

using namespace std;

int N, M, L;
int A[1002];

int cntPiece(int mid) {
	int cnt = 0, prev = 0;
	for (int i = 1; i <= M + 1; i++) {
		if (A[i] - A[prev] >= mid) {
			prev = i;
			cnt++;
		}
	}
	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> L;
	for (int i = 1; i <= M; i++) {
		cin >> A[i];
	}
	A[M + 1] = L;
	while (N--) {
		int Q;
		cin >> Q;
		int s = 0, e = L + 1;
		while (s + 1 < e) {
			int mid = (s + e) / 2;
			if (Q <= cntPiece(mid) - 1) {
				s = mid;
			} else {
				e = mid;
			}
		}
		cout << s << '\n';
	}

	return 0;
}