#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using cc = pair<char, char>;

int N;
int A[52][52];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	cin.ignore();
	fill(&A[0][0], &A[52][0], 1e9);
	for (int i = 0; i < N; i++) {
		string s;
		getline(cin, s);
		int a, b, sIdx = 0, eIdx = s.size() - 1;
		if ('a' <= s[sIdx] && s[sIdx] <= 'z')
			a = s[sIdx] - 'a' + 26;
		else
			a = s[sIdx] - 'A';
		if ('a' <= s[eIdx] && s[eIdx] <= 'z')
			b = s[eIdx] - 'a' + 26;
		else
			b = s[eIdx] - 'A';
		if (a == b) continue;
		A[a][b] = 1;
	}
	for (int i = 0; i < 52; i++)
		A[i][i] = 0;
	for (int k = 0; k < 52; k++) {
		for (int i = 0; i < 52; i++) {
			for (int j = 0; j < 52; j++) {
				A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
			}
		}
	}
	vector<cc> answer;
	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {
			if (A[i][j] == 1e9 || A[i][j] == 0) continue;
			char a, b;
			if (0 <= i && i <= 25)
				a = 'A' + i;
			else
				a = 'a' + i - 26;
			if (0 <= j && j <= 25)
				b = 'A' + j;
			else
				b = 'a' + j - 26;
			answer.push_back({a, b});
		}
	}
	cout << answer.size() << '\n';
	for (auto [a, b] : answer) {
		cout << a << " => " << b << '\n';
	}
	return 0;
}