#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int *score;
	score = ( int * )malloc( sizeof( int ) * n );

	for( int i = 0; i < n; i++ )
	{
		cin >> score[ i ];
	}

	double max_score = 0;

	for( int i = 0; i < n; i++ )
	{
		if( score[ i ] > max_score )
		{
			max_score = score[ i ];
		}
	}

	double result_score = 0;
	for( int i = 0; i < n; i++ )
	{
		result_score += ( score[ i ] / max_score * 100 );
	}

	result_score /= n;
	
	cout << result_score << endl;

	return 0;
}