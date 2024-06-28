#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int N, M, A, B;
set<int> S[4001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		S[A].insert(B);
		S[B].insert(A);
	}
	int answer = 1e9;
	for (int i = 1; i <= N; i++) {
		for (auto it = S[i].begin(); it != S[i].end(); it++) {
			for (auto it2 = S[*it].begin(); it2 != S[*it].end(); it2++) {
				if (S[*it2].find(i) != S[*it2].end())
					answer = min(answer, (int)(S[i].size() + S[*it].size() + S[*it2].size()) - 6);
			}
		}
	}

	if (answer == 1e9)
		cout << "-1\n";
	else
		cout << answer << '\n';
	return 0;
}

