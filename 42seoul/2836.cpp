#include <iostream>
#include <vector>
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
		int s, e;
		cin >> s >> e;
		if (s > e)
			A.push_back({e, s});
	}
	sort(A.begin(), A.end());
	long answer = M;
	int s = -1, e = -1;
	for (int i = 0; i < A.size(); i++) {
		if (e >= A[i].first) {
			e = max(e, A[i].second);
		} else {
			answer += (e - s) * 2;
			s = A[i].first;
			e = A[i].second;
		}
	}
	answer += (e - s) * 2;
	cout << answer << '\n';
	return 0;
}