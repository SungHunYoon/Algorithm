#include <iostream>
#include <algorithm>

using namespace std;

string S;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S;
	string A;
	A.push_back(S[0]);
	for (int i = 1; i < S.size(); i++) {
		if (A[i - 1] < S[i]) {
			A = S[i] + A;
		} else {
			A = A + S[i];
		}
	}
	reverse(A.begin(), A.end());
	cout << A << '\n';
	return 0;
}