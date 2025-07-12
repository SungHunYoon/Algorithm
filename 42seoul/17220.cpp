#include <iostream>
#include <vector>

using namespace std;

int N, M, L;
vector<int> V[26];
vector<int> rV[26];
bool visited[26];

int dfs(int idx) {
	int ret = 1;
	visited[idx] = true;
	for (auto v : V[idx]) {
		if (visited[v]) continue;
		ret += dfs(v);
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		char a, b;
		cin >> a >> b;
		int aIdx = a - 'A', bIdx = b - 'A';
		V[aIdx].push_back(bIdx);
		rV[bIdx].push_back(aIdx);
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		char a;
		cin >> a;
		visited[a - 'A'] = true;
	}
	int answer = 0;
	for (int i = 0; i < N; i++) {
		if (V[i].size() && !rV[i].size() && !visited[i]) {
			answer += dfs(i) - 1;
		}
	}
	cout << answer << '\n';
	return 0;
}