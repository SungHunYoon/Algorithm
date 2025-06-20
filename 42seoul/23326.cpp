#include <iostream>
#include <set>

using namespace std;

int N, Q, D = 1;
int A[500001];
set<int> S;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		if (A[i] == 1)
			S.insert(i);
	}
	while (Q--) {
		int a, b;
		cin >> a;
		if (a == 1) {
			cin >> b;
			A[b] = !A[b];
			if (A[b] == 1)
				S.insert(b);
			else
				S.erase(b);
		} else if (a == 2) {
			cin >> b;
			D = (D + b) % N;
			D = (D == 0 ? N : D);
		} else {
			if (S.empty())
				cout << "-1\n";
			else {
				auto it = S.lower_bound(D);
				if (it == S.end())
					cout << (N - D) + *(S.begin()) << '\n';
				else
					cout << *it - D << '\n';
			}
		}
	}
	return 0;
}