#include <iostream>
#include <algorithm>

using namespace std;
using ll = pair<long, long>;

int N;
ll A[100001];

bool cmp(ll &a, ll &b) {
	return (2 * a.first + 1) * b.second < (2 * b.first + 1) * a.second;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A + 1, A + N + 1, cmp);
	long answer = 0, time = 0;
	for (int i = 1; i <= N; i++) {
		time += A[i].first;
		answer += A[i].second * (time + (i - 1));
		time += A[i].first;
	}
	cout << answer << '\n';
	return 0;
}