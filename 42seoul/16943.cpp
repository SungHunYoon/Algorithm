#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string A;
int B;
bool visit[10];
int answer;

void dfs(int comb, int idx) {
	if (idx >= A.size()) {
		if (to_string(comb).size() == A.size() && comb < B)
			answer = max(answer, comb);
		return;
	}
	for (int i = 0; i < A.size(); i++) {
		if (!visit[i]) {
			visit[i] = true;
			dfs(comb * 10 + (A[i] - '0'), idx + 1);
			visit[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> A >> B;
	dfs(0, 0);
	if (answer == 0)
		cout << "-1\n";
	else
		cout << answer << '\n';

	return 0;
}