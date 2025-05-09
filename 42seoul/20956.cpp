#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M;
vector<ii> A;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		A.push_back({n, i + 1});
	}
	sort(A.begin(), A.end());
	deque<ii> dq;
	bool flag = false;
	while (M--) {
		if (dq.empty()) {
			int T = A.back().first;
			while (!A.empty() && A.back().first == T) {
				dq.push_front(A.back());
				A.pop_back();
			}
		}
		if (flag) {
			cout << dq.back().second << '\n';
			if (dq.back().first % 7 == 0)
				flag = !flag;
			dq.pop_back();
		} else {
			cout << dq.front().second << '\n';
			if (dq.front().first % 7 == 0)
				flag = !flag;
			dq.pop_front();
		}
	}
	return 0;
}