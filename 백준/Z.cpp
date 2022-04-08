#include <stdio.h>

int main()
{
	int count, a, b;

	scanf( "%d %d %d", &count, &a, &b );

	int total_count = 0;

	do
	{
		if( a == b )
		{
			break;
		}
		count /= 2;
		int c = a % 2;
		a = a / 2 + c;
		int d = b % 2;
		b = b / 2 + d;

		total_count++;
	} while( count != 0 );

	printf( "%d", total_count );

	getchar();
}