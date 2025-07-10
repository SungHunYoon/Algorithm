#include <iostream>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M;
int A[500001];
ii B[1000001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= N; i++) {
		int prev = (i - 1 < 1 ? N : i - 1);
		int next = (i + 1 > N ? 1 : i + 1);
		B[A[i]] = {A[prev], A[next]};
	}
	while (M--) {
		string S;
		int i, j;
		cin >> S;
		if (S == "BN") {
			cin >> i >> j;
			cout << B[i].second << '\n';
			B[j] = {i, B[i].second};
			B[B[i].second].first = j;
			B[i].second = j;
		} else if (S == "BP") {
			cin >> i >> j;
			cout << B[i].first << '\n';
			B[j] = {B[i].first, i};
			B[B[i].first].second = j;
			B[i].first = j;
		} else if (S == "CN") {
			cin >> i;
			cout << B[i].second << '\n';
			B[i].second = B[B[i].second].second;
			B[B[i].second].first = i;
		} else {
			cin >> i;
			cout << B[i].first << '\n';
			B[i].first = B[B[i].first].first;
			B[B[i].first].second = i;
		}
	}

	return 0;
}