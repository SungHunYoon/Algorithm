#include <iostream>

using namespace std;

int time[ 1000 ];
bool check[ 1000 ];

int main()
{
	int people_cnt;
	cin >> people_cnt;

	for( int i = 0; i < people_cnt; i++ )
	{
		cin >> time[ i ];
	}

	int result = 0;
	int temp = 0;
	for( int j = 0; j < people_cnt; j++ )
	{
		int people;
		int min = 1500;
		for( int i = 0; i < people_cnt; i++ )
		{
			if( min > time[ i ] && !check[ i ] )
			{
				//check[ i ] = true;
				min = time[ i ];
				people = i;
				//break;
			}
		}
		check[ people ] = true;
		temp = temp + min;
		result += temp;
	}

	cout << result << endl;

	return 0;
}