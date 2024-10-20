#include <iostream>
#include <vector>
using namespace std;

int N;
int A[21][21];
int answer = 1e9;

void dfs(vector<int> v, int idx) {
	if (idx >= N) {
		int stat = 0;
		bool visit[21] = { 0, };
		for (int i = 0; i < v.size(); i++) {
			visit[v[i]] = true;
			for (int j = i + 1; j < v.size(); j++) {
				stat += A[v[i]][v[j]];
				stat += A[v[j]][v[i]];
			}
		}
		int o = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (visit[i] || visit[j]) continue;
				o += A[i][j];
				o += A[j][i];
			}
		}
		answer = min(answer, abs(o - stat));
		return;
	}
	dfs(v, idx + 1);
	v.push_back(idx);
	dfs(v, idx + 1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];
	vector<int> v;
	dfs(v, 0);
	cout << answer << '\n';
	return 0;
}