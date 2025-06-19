#include <iostream>
#include <map>
#include <tuple>

using namespace std;
using iii = tuple<int, int, int>;

int N, M, A, B;
int arr[101][101];
map<iii, int> D;

int dfs(int x, int y, int cnt) {
	if (x > N || y > M)
		return 0;
	if (arr[x][y] == 1)
		cnt++;
	if (arr[x][y] == 2)
		return 0;
	if (cnt == A && x == N && y == M)
		return 1;
	auto it = D.find({cnt, x, y});
	if (it != D.end())
		return it->second;
	int ret = 0;
	ret += dfs(x + 1, y, cnt);
	ret += dfs(x, y + 1, cnt);
	return D[{cnt, x, y}] = ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> A >> B;
	for (int i = 0; i < A; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
	}
	for (int i = 0; i < B; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 2;
	}
	cout << dfs(1, 1, 0) << '\n';
	return 0;
}