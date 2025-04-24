#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
using ii = tuple<int, int>;
using iii = tuple<int, int, int>;

int N;
iii A[100001];
int B[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int n, s, e;
		cin >> n >> s >> e;
		A[i] = {s, e, n};
	}
	sort(A, A + N);
	int num = 1, answer = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	for (int i = 0; i < N; i++) {
		auto [s, e, n] = A[i];
		if (!pq.empty() && get<0>(pq.top()) <= s) {
			auto [qe, qr] = pq.top(); pq.pop();
			B[n] = qr;
			pq.push({e, qr});
		} else {
			B[n] = num;
			pq.push({e, num++});
			answer = max(answer, (int)pq.size());
		}
	}
	cout << answer << '\n';
	for (int i = 1; i <= N; i++)
		cout << B[i] << '\n';
	return 0;
}