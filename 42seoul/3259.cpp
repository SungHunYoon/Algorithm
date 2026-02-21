#include <iostream>
#include <vector>

using namespace std;

int N;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vector<vector<int>> T(N + 1), F(N + 1);
	for (int i = 1; i <= N; i++) {
		int tN, fN;
		cin >> tN;
		vector<int> trueList(tN);
		for (int j = 0; j < tN; j++) {
			cin >> trueList[j];
		}
		cin >> fN;
		vector<int> falseList(fN);
		for (int j = 0; j < fN; j++) {
			cin >> falseList[j];
		}
		T[i] = trueList;
		F[i] = falseList;
	}
	for (int i = 0; i < (1 << N); i++) {
		bool flag = true;
		for (int j = 1, idx = 1; j < (1 << N); j <<= 1, idx++) {
			if (i & j) {
				for (auto n : T[idx]) {
					if (!(i & (1 << (n - 1)))) {
						flag = false;
					}
				}
				for (auto n : F[idx]) {
					if (i & (1 << (n - 1))) {
						flag = false;
					}
				}
			} else {
				bool isLie = false;
				for (auto n : T[idx]) {
					if (!(i & (1 << (n - 1)))) {
						isLie = true;
					}
				}
				for (auto n : F[idx]) {
					if ((i & (1 << (n - 1)))) {
						isLie = true;
					}
				}
				if (!isLie) {
					flag = false;
				}
			}
		}
		if (flag) {
			for (int j = 1; j < (1 << N); j <<= 1) {
				cout << ((i & j) ? "true\n" : "false\n");
			}
			break;
		}
	}

	return 0;
}