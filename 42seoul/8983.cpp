#include <iostream>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int M, N, L;
int A[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> N >> L;
	for (int i = 0; i < M; i++)
		cin >> A[i];
	sort(A, A + M);
	int answer = 0;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		auto it1 = lower_bound(A, A + M, a);
		auto it2 = upper_bound(A, A + M, a);
		if (it1 != A && *it1 != a)
			it1--;
		if (it2 == A + M)
			it2--;
		int d1 = abs(*it1 - a) + b;
		int d2 = abs(*it2 - a) + b;
		if (d1 <= L || d2 <= L)
			answer++;
	}
	cout << answer << '\n';
	return 0;
}