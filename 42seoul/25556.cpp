#include <iostream>

using namespace std;

int N;
int arr[4];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		int j;
		for (j = 0; j < 4; j++)
		{
			if (arr[j] < num)
				break;
		}
		if (j == 4)
		{
			cout << "NO\n";
			return 0;
		}
		arr[j] = num;
	}
	cout << "YES\n";
	return 0;
}