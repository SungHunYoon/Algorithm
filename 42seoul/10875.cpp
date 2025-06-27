#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int L, N;
ii A[1001];
vector<ii> V;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool isVertical(int x1, int y1, int x2, int y2) {
	return (x1 != x2 ? true : false);
}

long calDie(long x, long y, long nx, long ny, long cx1, long cy1, long cx2, long cy2, int d) {
	bool cState = isVertical(x, y, nx, ny);
	bool pState = isVertical(cx1, cy1, cx2, cy2);
	if (cState == 0 && pState == 0) {
		if (d < 2) {
			if (x == cx1 && y <= min(cy1, cy2) && min(cy1, cy2) <= ny) return min(cy1, cy2) - y - 1;
		} else {
			if (x == cx1 && y <= max(cy1, cy2) && max(cy1, cy2) <= ny) return ny - max(cy1, cy2) - 1;
		}
	} else if (cState == 0 && pState == 1) {
		if (d < 2) {
			if ((min(cx1, cx2) <= x && x <= max(cx1, cx2)) && (y < cy1 && cy1 <= ny)) return cy1 - y - 1;
		} else {
			if ((min(cx1, cx2) <= x && x <= max(cx1, cx2)) && (y <= cy1 && cy1 < ny)) return ny - cy1 - 1;
		}
		
	} else if (cState == 1 && pState == 0) {
		if (d < 2) {
			if ((x < cx1 && cx1 <= nx) && (min(cy1, cy2) <= y && y <= max(cy1, cy2))) return cx1 - x - 1;
		} else {
			if ((x <= cx1 && cx1 < nx) && (min(cy1, cy2) <= y && y <= max(cy1, cy2))) return nx - cx1 - 1;
		}
	} else {
		if (d < 2) {
			if (y == cy1 && x <= min(cx1, cx2) && min(cx1, cx2) <= nx) return min(cx1, cx2) - x - 1;
		}
		else {
			if (y == cy1 && x <= max(cx1, cx2) && max(cx1, cx2) <= nx) return nx - max(cx1, cx2) - 1;
		}
	}
	return 1e9;
}

long rangeOut(long x, long y, long nx, long ny, int d) {
	if (-L > y && d == 2) {
		return ny - -L;
	} else if (ny > L && d == 0) {
		return L - y;
	} else if (-L > x && d == 3) {
		return nx - -L;
	} else if (nx > L && d == 1) {
		return L - x;
	}
	return 0;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> L >> N;
	for (int i = 0; i < N; i++) {
		int t;
		char d;
		cin >> t >> d;
		if (d == 'L') {
			A[i] = {t, 0};
		}
		else {
			A[i] = {t, 1};
		}
	}
	if (N == 0) {
		cout << L + 1 << '\n';
		return 0;
	}
	A[N] = {2 * L + 1, 0};
	V.push_back({0, 0});
	int d = 0;
	long answer = 1;
	bool flag = false;
	for (int i = 0; i <= N; i++) {
		auto [x, y] = V.back();
		int nx = x + A[i].first * dx[d];
		int ny = y + A[i].first * dy[d];
		int cx1 = x, cy1 = y, cx2 = nx, cy2 = ny;
		if (d > 1) {
			swap(cx1, cx2);
			swap(cy1, cy2);
		}
		long die = 1e9;
		for (int j = 0; j < V.size() - 1; j++) {
			auto [px1, py1] = V[j];
			auto [px2, py2] = V[j + 1];
			die = min(die, calDie(cx1, cy1, cx2, cy2, px1, py1, px2, py2, d));
		}
		if (die != 1e9) {
			answer += die;
			break;
		}
		long out = rangeOut(cx1, cy1, cx2, cy2, d);
		if (out) {
			answer += out;
			break;
		}
		V.push_back({nx, ny});
		if (A[i].second == 0)
			d++;
		else
			d--;
		d = (d + 4) % 4;
		answer += A[i].first;
	}
	cout << answer << '\n';
	return 0;
}