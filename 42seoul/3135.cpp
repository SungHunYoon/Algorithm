#include <iostream>
#include <algorithm>

using namespace std;

int A, B, N;
int arr[5];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> A >> B >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int answer = abs(A - B);
	for (int i = 0; i < N; i++)
		answer = min(answer, abs(arr[i] - B) + 1);
	cout << answer << '\n';
	return 0;
}
