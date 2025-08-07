#include <iostream>

using namespace std;

string S;
int M;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> M) {
		if (M == 0)
			break;
		cin.ignore();
		getline(cin, S);
		int A[129] = { 0, };
		int s = 0, e = 0, answer = 0, cnt = 0, cur = 0;
		while (e < S.size()) {
			if (!A[S[e]]) {
				cnt++;
			}
			A[S[e]]++;
			e++;
			cur++;
			while (cnt > M) {
				A[S[s]]--;
				if (!A[S[s]]) {
					cnt--;
				}
				s++;
				cur--;
			}
			answer = max(answer, cur);
		}
		cout << answer << '\n';
	}

	return 0;
}