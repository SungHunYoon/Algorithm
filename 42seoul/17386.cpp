#include <iostream>
#include <algorithm>

using namespace std;

pair<long long, long long> L1_start;
pair<long long, long long> L1_end;
pair<long long, long long> L2_start;
pair<long long, long long> L2_end;

long long ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3)
{
	return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> L1_start.first >> L1_start.second;
	cin >> L1_end.first >> L1_end.second;
	cin >> L2_start.first >> L2_start.second;
	cin >> L2_end.first >> L2_end.second;

	long long ret1 = ccw(L1_start.first, L1_start.second, L1_end.first, L1_end.second, L2_start.first, L2_start.second);
	long long ret2 = ccw(L1_start.first, L1_start.second, L1_end.first, L1_end.second, L2_end.first, L2_end.second);
	long long ret3 = ccw(L2_start.first, L2_start.second, L2_end.first, L2_end.second, L1_start.first, L1_start.second);
	long long ret4 = ccw(L2_start.first, L2_start.second, L2_end.first, L2_end.second, L1_end.first, L1_end.second);

	if (ret1 > 0 && ret3 < 0 && ret2 < 0 && ret4 > 0)
		cout << "1\n";
	else if (ret1 < 0 && ret3 > 0 && ret2 > 0 && ret4 < 0)
		cout << "1\n";
	else
		cout << "0\n";
	return 0;
}