#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main( int argc, char *argv[] )
{
	unsigned int N = 0, K = 0;

	unsigned int count = 0;

	//printf( "N, K input : " );

	scanf( "%d %d", &N, &K );

	unsigned int moneyArray[ N ];

	for( int i = 0; i < N; i++ )
	{
		scanf( "%d", &moneyArray[ i ] );

		if( moneyArray[ 0 ] != 1 )
		{
			//printf( "The first money should be 1.\n" );

			return 0;
		}
		else if( i > 0 && ( moneyArray[ i ] % moneyArray[ i - 1 ] ) != 0 && moneyArray[ i ] == 0 )
		{
			//printf( "This is not a multiple of the previous money.\n" );

			return 0;
		}
	}

	for( int j = N - 1; j >= 0; j-- )
	{
		if( moneyArray[ j ] > K )
		{
			continue;
		}
		else
		{
			count += K / moneyArray[ j ];

			K %= moneyArray[ j ];
		}
	}

	printf( "%d\n", count );

	return 0;
}