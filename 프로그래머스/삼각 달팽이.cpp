#include <string>
#include <vector>

using namespace std;

int arr[ 1000 ][ 1000 ];

void triangle( int row, int col, int n, int next_n, int num )
{
	int r = row;
	int c = col;

	for( int i = 0; i < n; i++ )
	{
		arr[ r++ ][ c ] = num++;
	}

	r -= 1;
	c += 1;

	n--;
	if( n < 1 ) return;

	for( int i = 0; i < n; i++ )
	{
		arr[ r ][ c++ ] = num++;
	}

	r -= 1;
	c -= 1;

	n--;
	if( n < 1 ) return;

	for( int i = r; i > row; i-- )
	{
		c--;
		arr[ r-- ][ c ] = num++;
	}

	r += 1;

	n--;
	if( n < 1 ) return;

	triangle( r + 1, c, n, next_n, num );
}

vector<int> solution( int n ) 
{
	vector<int> answer;

	triangle( 0, 0, n, n, 1 );

	for( int i = 0; i < n; i++ )
	{
		for( int j = 0; j < i + 1; j++ )
		{
			answer.push_back( arr[ i ][ j ] );
		}
	}

	return answer;
}