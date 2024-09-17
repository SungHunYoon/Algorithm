#include <iostream>

using namespace std;

string S;

int recursive(string &S, int idx, int P) {
	if (idx >= S.size() && (P == 4 || P == 3))
		return 1;
	if ((P != 1 && P != 2) && idx + 1 < S.size() && S[idx] == '1' && S[idx + 1] == '0') {
		if (recursive(S, idx + 2, 1))
			return 1;
	}
	if ((P != 1 && P != 2) && idx + 1 < S.size() && S[idx] == '0' && S[idx + 1] == '1') {
		if (recursive(S, idx + 2, 4))
			return 1;
	}
	if ((P == 1 || P == 2) && S[idx] == '0') {
		P = 2;
		if (recursive(S, idx + 1, 2))
			return 1;
	} 
	if ((P == 2 || P == 3) && S[idx] == '1') {
		P = 3;
		if (recursive(S, idx + 1, 3))
			return 1;
	}
	return 0;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S;
	if (recursive(S, 0, 0))
		cout << "SUBMARINE\n";
	else
		cout << "NOISE\n";
	return 0;
}