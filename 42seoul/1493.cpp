#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
using LL = long long;

LL L, W, H, N;
pair<LL, LL> arr[21];
LL answer;

LL dfs(LL l, LL w, LL h, LL n, LL cnt)
{
	LL ret = cnt;
	if (l <= 0 || w <= 0 || h <= 0 || n < 0)
		return ret;
	LL p = pow(2, arr[n].first);
	
	// cout << l << " " << w << " " << h << " " << p << '\n';
	if (l >= p && w >= p && h >= p && arr[n].second > 0)
	{
		arr[n].second--;
		LL a, b, c;
		a = dfs(l - p, w, p, n, cnt);
		b = dfs(l - (l - p), w - p, p, n, cnt);
		c = dfs(l, w, h - p, n, cnt);
		if (a == -1 || b == -1 || c == -1)
			return -1;
		ret += a + b + c + 1;
	}
	else if (n == 0 && arr[n].second == 0)
		return -1;
	else
	{
		LL t;
		t = dfs(l, w, h, n - 1, cnt);
		if (t == -1)
			return -1;
		ret += t;
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> L >> W >> H >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N);
	cout << dfs(L, W, H, N - 1, 0) << '\n';
	return 0;
}
