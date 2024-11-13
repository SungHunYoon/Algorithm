#include <iostream>

using namespace std;

long N;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	if (N % 7 == 0 || N % 7 == 2)
		cout << "CY\n";
	else
		cout << "SK\n";
	return 0;
}
