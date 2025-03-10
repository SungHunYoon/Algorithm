#include <iostream>

using namespace std;

string N;

int calOdd(int n) {
	int ret = n % 2;
	while (n > 0) {
		n /= 10;
		ret += n % 2;
	}
	return ret;
}

int DQ(string n, int type) {
	int odd = calOdd(stoi(n));
	if (n.size() == 1) {
		return odd;
	} else if (n.size() == 2) {
		int calN = (n[0] - '0') + (n[1] - '0');
		return odd + DQ(to_string(calN), type);
	} else {
		int ret = (type == 1 ? 1e9 : 0);
		for (int i = 1; i < n.size(); i++) {
			for (int j = 1; j < n.size(); j++) {
				for (int k = 1; k < n.size(); k++) {
					if (i + j + k != n.size()) continue;
					int calN = stoi(n.substr(0, i)) + stoi(n.substr(i, j)) + stoi(n.substr(i + j, k));
					int calDQ = DQ(to_string(calN), type);
					if (type == 1)
						ret = min(ret, odd + calDQ);
					else
						ret = max(ret, odd + calDQ);
				}
			}
		}
		return ret;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	cout << DQ(N, 1) << " " << DQ(N, 0) << '\n';
	return 0;
}