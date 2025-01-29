#include <iostream>
#include <vector>

using namespace std;

int N;
int A[200001];
vector<int> T[200001];
bool V[200001];

int dfs(int idx, int color) {
	int ret = 0;
	V[idx] = true;
	if (A[idx] != color) {
		ret++;
		color = A[idx];
	}
	for (auto n : T[idx]) {
		if (V[n]) continue;
		ret += dfs(n, color);
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	for (int i = 1; i <= N - 1; i++) {
		int a, b;
		cin >> a >> b;
		T[a].push_back(b);
		T[b].push_back(a);
	}
	cout << dfs(1, 0) << '\n';
	return 0;
}