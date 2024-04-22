#include <iostream>

using namespace std;

int N;
int arr[100001];
int cnt[2];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < N; i++)
	{
		int div = arr[i] / 2;
		int mod = arr[i] % 2;
		cnt[0] += mod;
		cnt[1] += div;
	}
	while (cnt[1] >= cnt[0])
	{
		if (cnt[1] == cnt[0])
		{
			cout << "YES\n";
			return 0;
		}
		cnt[0] += 2;
		cnt[1]--;
	}
	cout << "NO\n";
	return 0;
}
