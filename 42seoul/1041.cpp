#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

long N;
long arr[6];

long checkTwoValue()
{
	long minValue = min(LONG_MAX, arr[0] + arr[1]);
	minValue = min(minValue, arr[0] + arr[2]);
	minValue = min(minValue, arr[0] + arr[3]);
	minValue = min(minValue, arr[0] + arr[4]);
	minValue = min(minValue, arr[1] + arr[2]);
	minValue = min(minValue, arr[1] + arr[3]);
	minValue = min(minValue, arr[1] + arr[5]);
	minValue = min(minValue, arr[4] + arr[2]);
	minValue = min(minValue, arr[4] + arr[3]);
	minValue = min(minValue, arr[4] + arr[5]);
	minValue = min(minValue, arr[5] + arr[2]);
	minValue = min(minValue, arr[5] + arr[3]);
	return minValue;
}

long checkThreeValue()
{
	long minValue = min(LONG_MAX, arr[0] + arr[1] + arr[2]);
	minValue = min(minValue, arr[0] + arr[1] + arr[3]);
	minValue = min(minValue, arr[0] + arr[2] + arr[4]);
	minValue = min(minValue, arr[0] + arr[3] + arr[4]);
	minValue = min(minValue, arr[1] + arr[2] + arr[5]);
	minValue = min(minValue, arr[1] + arr[3] + arr[5]);
	minValue = min(minValue, arr[4] + arr[2] + arr[5]);
	minValue = min(minValue, arr[4] + arr[3] + arr[5]);
	return minValue;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < 6; i++)
		cin >> arr[i];
	long answer = 0;
	if (N == 1)
	{
		for (int i = 0; i < 6; i++)
			answer += arr[i];
		answer -= *max_element(arr, arr + 6);
		cout << answer << '\n';
		return 0;
	}
	long minValue = *min_element(arr, arr + 6);
	long two = checkTwoValue();
	long three = checkThreeValue();

	answer += minValue * (N - 2) * (N - 1) * 4L;
	//cout << answer << '\n';
	answer += (N - 2) * (N - 2) * minValue;
	//cout << answer << '\n';
	answer += two * (N - 1) * 4L + two * (N - 2) * 4L;
	//cout << answer << '\n';
	answer += three * 4L;

	cout << answer << '\n';

	return 0;
}

//   D
// E A B F
//   C

// A B
// A C
// A D
// A E
// B C
// B D
// B F
// E C
// E D
// E F
// F C
// F D

// A B C
// A B D
// A C E
// A D E
// B C F
// B D F
// E C F
// E D F

// min * (N - 2) * (N - 1) * 4
// (N - 2) * (N - 2) * min
// two * (N - 1) * 4 + two * (N - 2) * 4
// three * 4