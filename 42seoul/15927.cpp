#include <iostream>
#include <algorithm>

using namespace std;

string S;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S;
	int s = 0, e = S.size() - 1;
	bool flag = true;
	while (s <= e) {
		if (S[s++] != S[e--]) {
			flag = false;
			break;
		}
	}
	if (count(S.begin(), S.end(), S[0]) == S.size())
		cout << "-1\n";
	else if (flag)
		cout << S.size() - 1 << '\n';
	else
		cout << S.size() << '\n';
	return 0;
}
