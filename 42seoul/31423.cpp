#include <iostream>
#include <vector>

using namespace std;

int N;
int inDegree[500001];
string S[500001];
vector<int> V[500001];

void dfs(int idx) {
	cout << S[idx];
	for (auto v : V[idx]) {
		dfs(v);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> S[i];
	}
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		inDegree[b]++;
		V[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] != 0) continue;
		dfs(i);
		cout << '\n';
		break;
	}
	return 0;
}