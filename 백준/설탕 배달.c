#include <stdio.h>

int calculate_Kg( int input_Kg )
{
	int result = -1;

	int max = input_Kg / 3;
	for( int i = 0; i < max + 1; i++ )
	{
		int temp = input_Kg;
		temp -= i * 3;

		int count = 0;
		count = i + temp / 5;

		temp %= 5;

		if( temp == 0 )
		{
			if( result < 0 || result > count )
			{
				result = count;
			}
		}
	}

	return result;
}

int main()
{
	int input_Kg;

	scanf( "%d", &input_Kg );

	int result = calculate_Kg( input_Kg );

	printf( "%d", result );

	return 0;
}