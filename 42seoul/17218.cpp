#include <iostream>

using namespace std;

string A, B;
string D[41][41];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> A >> B;
	for (int i = 1; i <= A.size(); i++) {
		for (int j = 1; j <= B.size(); j++) {
			if (A[i - 1] == B[j - 1]) {
				D[i][j] = D[i - 1][j - 1] + A[i - 1];
			} else {
				if (D[i - 1][j].size() >= D[i][j - 1].size())
					D[i][j] = D[i - 1][j];
				else
					D[i][j] = D[i][j - 1];
			}
		}
	}
	cout << D[A.size()][B.size()] << '\n';
	return 0;
}