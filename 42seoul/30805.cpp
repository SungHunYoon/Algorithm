#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M;
int A[101], B[101];
vector<ii> D[101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	cin >> M;
	for (int i = 1; i <= M; i++)
		cin >> B[i];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			ii p = {i, j};
			if (A[i] == B[j] && (D[A[i]].empty() || D[A[i]].back() < p))
				D[A[i]].push_back(p);
		}
	}
	vector<ii> answer;
	for (int i = 100; i >= 1; i--) {
		for (auto it = D[i].begin(); it != D[i].end(); it++) {
			if (answer.empty())
				answer.push_back(*it);
			else {
				ii p = answer.back();
				if ((p.first < it->first && p.second < it->second))
					answer.push_back(*it);
			}
		}
	}
	cout << answer.size() << '\n';
	for (auto [i, j] : answer)
		cout << A[i] << ' ';
	cout << '\n';
	return 0;
}