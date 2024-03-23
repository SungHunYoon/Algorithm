#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> p1;
pair<int, int> p2;
pair<int, int> p3;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> p1.first >> p1.second;
	cin >> p2.first >> p2.second;
	cin >> p3.first >> p3.second;

	double ret = (p2.first - p1.first) * (p3.second - p1.second);
	ret -= (p3.first - p1.first) * (p2.second - p1.second);
	if (ret > 0)
		cout << "1\n";
	else if (ret == 0)
		cout << "0\n";
	else
		cout << "-1\n";

	return 0;
}