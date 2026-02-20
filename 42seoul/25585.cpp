#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N;
int A[101][101];

int permutation(vector<ii> &dq, vector<ii> &sel, vector<int> &visit) {
	if (sel.size() >= dq.size() + 1) {
		int time = 0;
		for (int i = 1; i < sel.size(); i++) {
			time += max(abs(sel[i - 1].first - sel[i].first), abs(sel[i - 1].second - sel[i].second));
		}
		return time;
	}
	int ret = 1e9;
	for (int i = 0; i < dq.size(); i++) {
		if (visit[i]) continue;
		visit[i] = true;
		sel.push_back(dq[i]);
		ret = min(ret, permutation(dq, sel, visit));
		sel.pop_back();
		visit[i] = false;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vector<ii> dq, sel;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			if (A[i][j] == 1) {
				dq.push_back({i, j});
			} else if (A[i][j] == 2) {
				sel.push_back({i, j});
			}
		}
	}
	bool isPossible = true;
	for (int i = 0; i < dq.size(); i++) {
		auto [x, y] = dq[i];
		int checkDiag1 = (x % 2 + y % 2) % 2;
		int checkDiag2 = (sel[0].first % 2 + sel[0].second % 2) % 2;
		if (checkDiag1 != checkDiag2) {
			isPossible = false;
		}
	}
	if (isPossible) {
		vector<int> visit(dq.size());
		cout << "Undertaker\n" << permutation(dq, sel, visit) << '\n';
	} else {
		cout << "Shorei\n";
	}

	return 0;
}