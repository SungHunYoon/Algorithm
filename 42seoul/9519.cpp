#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int X;
string S;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> X >> S;
	vector<string> T;
	for (int i = 0; i < S.size(); i++) {
		if (find(T.begin(), T.end(), S) != T.end())
			break;
		T.push_back(S);
		string A = S;
		int s = 0, e = S.size() - 1;
		for (int j = 0; j < S.size(); j++) {
			if (j % 2 == 0)
				A[s++] = S[j];
			else
				A[e--] = S[j];
		}
		S = A;
	}
	cout << T[X % T.size()] << '\n';
	return 0;
}