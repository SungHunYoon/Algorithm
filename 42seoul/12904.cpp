#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string S, T;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S >> T;
	string str = T;
	for (size_t i = T.size() - 1; i >= S.size(); i--)
	{
		str.pop_back();
		if (str[i] == 'B')
			reverse(str.begin(), str.end());
		//cout << str << '\n';
	}
	if (str == S)
		cout << "1\n";
	else
		cout << "0\n";
	return 0;
}

// B
// BA
// ABB
// ABBA