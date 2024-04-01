#include <iostream>
#include <string>

using namespace std;

string str;
char ucpc[4] = {'U', 'C', 'P', 'C'};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	getline(cin, str);
	int idx = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		//cout << ucpc[idx] << " " << str[i] << '\n';
		if (idx < 4 && ucpc[idx] == str[i])
			idx++;
	}
	if (idx == 4)
		cout << "I love UCPC\n";
	else
		cout << "I hate UCPC\n";
	return 0;
}