#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N;
int A[4001];
set<int> B, S;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		B.insert(A[i]);
	}
	for (int i = 2; i <= N / 2; i++) {
		int diff = A[i] - A[1];
		set<int> V;
		for (auto b : B) {
			if (B.find(b + diff) == B.end()) continue;
			V.insert(b);
			V.insert(b + diff);
		}
		if (B.size() == V.size()) {
			S.insert(diff);
		}
	}
	cout << S.size() << '\n';
	for (auto s : S) {
		cout << s << ' ';
	}
	cout << '\n';

	return 0;
}