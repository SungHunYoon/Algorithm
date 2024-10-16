#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, X, Y;
vector<int> V[1000001];
bool visit[1000001];
int answer;

int dfs(int idx) {
	int ret = 0;
	bool flag = false;
	visit[idx] = true;
	for (int i = 0; i < V[idx].size(); i++) {
		if (!visit[V[idx][i]]) {
			ret += dfs(V[idx][i]);
			flag = true;
		}
	}
	if (!flag)
		return 1;
	if (ret > 0) {
		answer++;
		ret = 0;
	} else
		ret = 1;
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> X >> Y;
		V[X].push_back(Y);
		V[Y].push_back(X);
	}
	dfs(1);
	cout << answer << '\n';
	return 0;
}