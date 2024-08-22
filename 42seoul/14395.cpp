#include <iostream>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

int S, T;
set<long> s;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S >> T;
	if (S == T) {
		cout << "0\n";
		return 0;
	}
	queue<pair<long, string>> q;
	q.push({S, ""});
	while (!q.empty()) {
		auto [val, str] = q.front(); q.pop();
		if (val == T) {
			cout << str << '\n';
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			long tVal;
			string tStr = str;
			if (i == 0) {
				tVal = val * val;
				if (!s.insert(tVal).second)
					continue;
				tStr.append("*");
			} else if (i == 1) {
				tVal = val + val;
				if (!s.insert(tVal).second)
					continue;
				tStr.append("+");
			} else if (i == 2) {
				tVal = val - val;
				if (!s.insert(tVal).second)
					continue;
				tStr.append("-");
			} else {
				if (val == 0)
					continue;
				tVal = val / val;
				if (!s.insert(tVal).second)
					continue;
				tStr.append("/");
			}
			q.push({tVal, tStr});
		}
	}
	cout << "-1\n";
	return 0;
}