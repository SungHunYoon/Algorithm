#include <iostream>
#include <numeric>
#include <queue>

using namespace std;

int N;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	long M = N, L = 1;
	while (M > 0) {
		int mod = M % 10;
		if (mod > 0) L = lcm(L, mod);
		M /= 10;
	}
	string sN = to_string(N);
	queue<string> q;
	q.push(sN);
	while (!q.empty()) {
		string s = q.front(); q.pop();
		if (stol(s) % L == 0) {
			cout << s << '\n';
			break;
		}
		for (int i = 0; i < 10; i++) {
			string nS = s;
			nS.append(1, i + '0');
			q.push(nS);
		}
	}
	return 0;
}