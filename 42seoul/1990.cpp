#include <iostream>

using namespace std;

int A, B;

bool isPalindrom(int n) {
	string str = to_string(n);
	for (long j = 0; j < str.size() / 2; j++)
		if (str[j] != str[str.size() - 1 - j])
			return false;
	return true;
}

bool isPrime(int n) {
	for (long j = 2; j * j <= n; j++)
		if (n % j == 0)
			return false;
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> A >> B;
	for (int i = A; i <= B && i <= 10000000; i++)
		if (isPalindrom(i) && isPrime(i))
			cout << i << '\n';
	cout << "-1\n";
	return 0;
}