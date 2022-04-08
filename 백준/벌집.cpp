#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	if( n < 1 || n >1000000000 )
	{
		return 0;
	}

	int result = 1;
	int temp_value = 1;
	// 1 / 7 / 19 / 37 / 61
	int i = 0;
	while( 1 )
	{
		temp_value += 6 * i++;
		if( n <= temp_value )
		{
			//result++;
			break;
		}
		result++;
	}
	cout << result << endl;

	return 0;
}