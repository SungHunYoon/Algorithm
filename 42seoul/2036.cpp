#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
using LL = long long;

int N;
deque<LL> P, M;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num; cin >> num;
		if (num > 0)
			P.push_back(num);
		else
			M.push_back(num);
	}
	sort(P.begin(), P.end(), greater<LL>());
	sort(M.begin(), M.end());
	LL answer = 0;
	while (P.size() > 1)
	{
		LL a = P.front(); P.pop_front();
		LL b = P.front(); P.pop_front();
		answer += max(a * b, a + b);
	}
	while (!P.empty())
	{
		LL a = P.front(); P.pop_front();
		answer += a;
	}
	while (M.size() > 1)
	{
		LL a = M.front(); M.pop_front();
		LL b = M.front(); M.pop_front();
		answer += max(a * b, a + b);
	}
	while (!M.empty())
	{
		LL a = M.front(); M.pop_front();
		answer += a;
	}
	cout << answer << '\n';
	return 0;
}
