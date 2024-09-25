#include <iostream>
#include <algorithm>

using namespace std;

string W;
int T, K;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> W >> K;
		int shortAnswer = 2e9;
		int longAnswer = 0;
		int A[26] { 0, };
		for (int i = 0; i < W.size(); i++)
			A[W[i] - 'a']++;
		for (int i = 0; i < W.size(); i++) {
			if (A[W[i] - 'a'] < K) continue;
			int cnt = 0;
			for (int start = i, end = i; end < W.size(); end++) {
				if (W[end] == W[start]) {
					cnt++;
					if (cnt == K) {
						shortAnswer = min(shortAnswer, end - start + 1);
						longAnswer = max(longAnswer, end - start + 1);
						start = end;
						break;
					}
				}
			}
			A[W[i] - 'a']--;
		}
		if (shortAnswer == 2e9 || longAnswer == 0)
			cout << "-1\n";
		else
			cout << shortAnswer << " " << longAnswer << '\n';
	}

	return 0;
}