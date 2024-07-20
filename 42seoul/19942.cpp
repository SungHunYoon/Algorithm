#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N;
int S[4];
int M[15][5];
set<pair<int, vector<int>>> answer;

void dfs(vector<int> idx, vector<int> val, int cnt) {
	if (cnt >= N) {
		for (int i = 0; i < val.size(); i++) {
			if (val[i] < S[i])
				return;
		}
		int sum = 0;
		for (int i = 0; i < idx.size(); i++)
			sum += M[idx[i]][4];
		answer.insert({sum, idx});
		return;
	}

	dfs(idx, val, cnt + 1);
	idx.push_back(cnt);
	for (int j = 0; j < 4; j++)
		val[j] += M[cnt][j];
	dfs(idx, val, cnt + 1);
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < 4; i++)
		cin >> S[i];
	for (int i = 0; i < N; i++)
		cin >> M[i][0] >> M[i][1] >> M[i][2] >> M[i][3] >> M[i][4];
	vector<int> idx;
	vector<int> val(4);
	dfs(idx, val, 0);
	if (answer.size() == 0) {
		cout << "-1\n";
		return 0;
	}
	auto it = answer.begin();
	cout << it->first << "\n";
	for (int i = 0; i < it->second.size(); i++)
		cout << it->second[i] + 1 << " ";
	cout << '\n';
	return 0;
}