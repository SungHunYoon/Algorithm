#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int input_sound[ 8 ];
	for( int i = 0; i < 8; i++ )
	{
		cin >> input_sound[ i ];
	}

	bool isAscending = false;
	bool isMixed = false;
	int expected_sound = 0;
	char result[ 20 ];
	for( int i = 0; i < 8; i++ )
	{
		if( i == 0 )
		{
			if( input_sound[ 0 ] == 1 )
			{
				isAscending = true;
				expected_sound = 1;
			}
			else if( input_sound[ 0 ] == 8 )
			{
				isAscending = false;
				expected_sound = 8;
			}
			else
			{
				isMixed = true;
				break;
			}
		}

		if( input_sound[ i ] != expected_sound )
		{
			isMixed = true;
			break;
		}

		if( isAscending )
		{
			expected_sound++;
		}
		else
		{
			expected_sound--;
		}
	}

	if( isMixed )
	{
		strncpy( result, "mixed", 5 );
	}
	else
	{
		if( isAscending )
		{
			strncpy( result, "ascending", 10 );
		}
		else
		{
			strncpy( result, "descending", 11 );
		}
	}
	cout << result << endl;

	return 0;
}