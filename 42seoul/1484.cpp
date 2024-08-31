#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int G;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> G;
	vector<int> answer;
	for (int i = 1; i < G; i++) {
		long Y = pow(i, 2);
		long X = Y + G;
		if (X == pow((int)sqrt(X), 2))
		 	answer.push_back(sqrt(X));
	}
	if (answer.empty()) {
		cout << "-1\n";
		return 0;
	}
	for (auto i : answer)
		cout << i << '\n';
	return 0;
}

// X^2 = Y^2 + G;