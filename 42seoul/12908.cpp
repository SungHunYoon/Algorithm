#include <iostream>

using namespace std;

long xs, ys, xe, ye;
long xt1[3], yt1[3], xt2[3], yt2[3];
bool visit[3];

long calculate(long cx, long cy, long tx, long ty) {
	return abs(cx - tx) + abs(cy - ty);
}

long dfs(long cx, long cy, long second) {
	long ret = 1e14;
	ret = min(ret, calculate(cx, cy, xe, ye) + second);

	for (int i = 0; i < 3; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		ret = min(ret, dfs(xt1[i], yt1[i], calculate(cx, cy, xt2[i], yt2[i]) + second + 10));
		ret = min(ret, dfs(xt2[i], yt2[i], calculate(cx, cy, xt1[i], yt1[i]) + second + 10));
		visit[i] = false;
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> xs >> ys >> xe >> ye;
	for (int i = 0; i < 3; i++) {
		cin >> xt1[i] >> yt1[i] >> xt2[i] >> yt2[i];
	}
	cout << dfs(xs, ys, 0) << '\n';
	return 0;
}