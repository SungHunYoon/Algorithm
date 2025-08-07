#include <iostream>
#include <algorithm>

using namespace std;
using ll = pair<long, long>;

int N, D;
ll A[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> D;
	for (int i = 1; i <= N; i++) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A + 1, A + N + 1);
	int s = 1, e = 1;
	long satisfy = 0, answer = 0;
	while (e <= N) {
		satisfy += A[e].second;
		long diff = A[e].first - A[s].first;
		while (diff >= D) {
			satisfy -= A[s].second;
			s++;
			diff = A[e].first - A[s].first;
		}
		answer = max(answer, satisfy);
		e++;
	}
	cout << answer << '\n';
	return 0;
}