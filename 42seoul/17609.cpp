#include <iostream>

using namespace std;

int T;
string S;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> S;
		int start = 0, end = S.size() - 1;
		while (start <= end) {
			if (S[start] != S[end])
				break;
			start++;
			end--;
		}
		if (start > end) {
			cout << "0\n";
			continue;
		}
		bool flag = true;
		int tStart = start + 1, tEnd = end;
		while (tStart <= tEnd) {
			if (S[tStart] != S[tEnd]) {
				flag = false;
				break;
			}
			tStart++;
			tEnd--;
		}
		if (flag) {
			cout << "1\n";
			continue;
		}
		flag = true;
		tStart = start; tEnd = end - 1;
		while (tStart <= tEnd) {
			if (S[tStart] != S[tEnd]) {
				flag = false;
				break;
			}
			tStart++;
			tEnd--;
		}
		if (flag) {
			cout << "1\n";
			continue;
		}
		cout << "2\n";
	}

	return 0;
}