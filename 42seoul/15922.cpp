#include <iostream>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N;
ii A[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i].first >> A[i].second;
	int answer = 0;
	int s = -1e9 - 7, e = -1e9 - 7;
	for (int i = 0; i < N; i++) {
		if (e >= A[i].first) {
			e = max(e, A[i].second);
		} else {
			answer += e - s;
			s = A[i].first;
			e = A[i].second;
		}
	}
	answer += e - s;
	cout << answer << '\n';
	return 0;
}