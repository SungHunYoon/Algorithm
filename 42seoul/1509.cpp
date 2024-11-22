#include <iostream>
#include <vector>
#include <map>

using namespace std;

string S;
map<int, vector<int>> P;
int D[2501];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S;
	for (int i = 1; i <= S.size(); i++) {
		for (int s = i, e = i; s >= 1 && e <= S.size(); s--, e++) {
			if (S[s - 1] != S[e - 1])
				break;
			P[e].push_back(s);
		}
		for (int s = i, e = i + 1; s >= 1 && e <= S.size(); s--, e++) {
			if (S[s - 1] != S[e - 1])
				break;
			P[e].push_back(s);
		}
	}
	fill(D + 1, D + S.size() + 1, 1e9);
	for (auto [a, v] : P) {
		for (auto i : v)
			D[a] = min(D[a], D[i - 1]);
		D[a] += 1;
	}
	cout << D[S.size()] << '\n';
	return 0;
}