#include <iostream>

using namespace std;

int N;
int arr[2001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	int index = 0;
	for (int i = 1; i <= 1000; i++)
	{
		arr[index] = i;
		arr[index + 1] = 1000 + i;
		index += 2;
	}
	cout << "2000\n";
	for (int i = 0; i < 2000; i++)
		cout << arr[i] << ' ';
	cout << '\n';

	return 0;
}