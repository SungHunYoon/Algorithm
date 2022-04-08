#include <iostream>
#include <cstdint>
#include <cstring>

using namespace std;

int64_t arr[ 31 ][ 31 ];

uint64_t pop( int w, int h )
{
	if( w == 0 && h == 0 )
	{
		return 1;
	}

	uint64_t result = 0;
	if( arr[ w ][ h ] > -1 )
	{
		result += arr[ w ][ h ];
	}
	else
	{
		if( w != 0 )
		{
			uint64_t temp1 = pop( w - 1, h + 1 );
			arr[ w - 1 ][ h + 1 ] = temp1;
			result += temp1;
		}
		if( h != 0 )
		{
			uint64_t temp2 = pop( w, h - 1 );
			arr[ w ][ h - 1 ] = temp2;
			result += temp2;
		}
	}
	return result;
}


// 1 w h
// 2 w h w h, w w h h
int main()
{
	int n;
	while( 1 )
	{
		cin >> n;
		if( n == 0 ) break;
		memset( arr, -1, sizeof( arr ) );
		cout << pop( n, 0 ) << endl;
	}
	return 0;
}