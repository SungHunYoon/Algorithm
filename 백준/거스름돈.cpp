#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int input;

	cin >> input;

	input = 1000 - input;

	int cnt = 0;

	while( input > 0 )
	{
		if( input - 500 >= 0 )
		{
			input -= 500;
			cnt++;
		}
		else if( input - 100 >= 0 )
		{
			input -= 100;
			cnt++;
		}
		else if( input - 50 >= 0 )
		{
			input -= 50;
			cnt++;
		}
		else if( input - 10 >= 0 )
		{
			input -= 10;
			cnt++;
		}
		else if( input - 5 >= 0 )
		{
			input -= 5;
			cnt++;
		}
		else if( input - 1 >= 0 )
		{
			input -= 1;
			cnt++;
		}
	}

	cout << cnt << endl;
	//getchar();

	return 0;
}