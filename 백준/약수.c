#include <stdio.h>
#include <stdlib.h>

void bubble_sort( int list[], int n )
{
	int i, j, temp;

	for( i = n - 1; i > 0; i-- )
	{
		for( j = 0; j < i; j++ )
		{
			if( list[ j ] < list[ j + 1 ] )
			{
				temp = list[ j ];
				list[ j ] = list[ j + 1 ];
				list[ j + 1 ] = temp;
			}
		}
	}
}

int main()
{
	int count;

	scanf( "%d", &count );

	int *input_array = ( int * )malloc( sizeof( int ) * count );

	for( int i = 0; i < count; i++ )
		scanf( "%d", &input_array[ i ] );

	bubble_sort( input_array, count );

	int number = input_array[ 0 ] * input_array[ count - 1 ];

	printf( "%d", number );

	getchar();
}