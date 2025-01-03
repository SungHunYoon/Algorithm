#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, H;
vector<int> A[51];
bool V[51];
int D[51][1001];

int dfs(int value, int idx) {
	int ret = 0;
	if (value == H)
		return D[idx][value] = 1;
	if (idx >= N)
		return D[idx][value] = 0;
	if (D[idx][value] > -1)
		return D[idx][value];
	ret = dfs(value, idx + 1);
	V[idx] = true;
	for (auto v : A[idx]) {
		if (value + v > H) continue;
		ret = (ret + dfs(value + v, idx + 1)) % 10007;
	}
	V[idx] = false;
	D[idx][value] = ret;
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	stringstream ss;
	getline(cin, s);
	ss << s; ss >> N; ss >> M; ss >> H;
	for (int i = 0; i < N; i++) {
		ss.clear();
		getline(cin, s);
		ss << s;
		while (!ss.eof()) {
			int n;
			ss >> n;
			A[i].push_back(n);
		}
	}
	fill(&D[0][0], &D[N][0], -1);
	cout << dfs(0, 0) << '\n';
	return 0;
}