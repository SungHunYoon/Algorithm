#include <iostream>

using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	int calculate_num = A * B * C;

	int num_arr[ 10 ] = { 0 };

	while( calculate_num > 0 )
	{
		switch( calculate_num % 10 )
		{
		case 0:
			num_arr[ 0 ] += 1;
			break;
		case 1:
			num_arr[ 1 ] += 1;
			break;
		case 2:
			num_arr[ 2 ] += 1;
			break;
		case 3:
			num_arr[ 3 ] += 1;
			break;
		case 4:
			num_arr[ 4 ] += 1;
			break;
		case 5:
			num_arr[ 5 ] += 1;
			break;
		case 6:
			num_arr[ 6 ] += 1;
			break;
		case 7:
			num_arr[ 7 ] += 1;
			break;
		case 8:
			num_arr[ 8 ] += 1;
			break;
		case 9:
			num_arr[ 9 ] += 1;
			break;
		}
		calculate_num /= 10;
	}

	for( int i = 0; i < 10; i++ )
	{
		cout << num_arr[ i ] << endl;
	}
	return 0;
}