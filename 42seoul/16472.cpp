#include <iostream>
#include <algorithm>

using namespace std;

int N;
int T[26];
string S;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> S;
	int s = 0, e = 0, answer = 0;
	while (e < S.size()) {
		T[S[e] - 'a']++;
		e++;
		while (26 - count(T, T + 26, 0) > N) {
			T[S[s] - 'a']--;
			s++;
		}
		answer = max(answer, e - s);
	}
	cout << answer << '\n';
	return 0;
}