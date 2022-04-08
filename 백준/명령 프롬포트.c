#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int count;

	//scanf_s( "%d", &count );
	scanf( "%d", &count );

	char **str = ( char ** )malloc( sizeof( char * ) * count );

	char *result = NULL;

	for( int i = 0; i < count; i++ )
	{
		str[ i ] = ( char * )malloc( sizeof( char ) * 50 );
		//scanf_s( "%s", str[ i ], 50 );
		scanf( "%s", str[ i ] );

		if( result == NULL )
		{
			result = str[ i ];
		}
		else
		{
			for( int j = 0; j < strlen( str[ i ] ); j++ )
			{
				if( str[ i ][ j ] != result[ j ] )
				{
					result[ j ] = '?';
				}
			}
		}
	}

	printf( "%s\n", result );
	getchar();
}