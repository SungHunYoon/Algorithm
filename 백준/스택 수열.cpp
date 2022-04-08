#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	// example
	// 8 4 3 6 8 7 5 2 1
	// + + + + - - + + - + + - - - - -
	// 5 1 2 5 3 4
	// NO
	// 1 4 3 2 5
	int *arr;
	arr = ( int * )malloc( sizeof( int * ) * n );

	for( int i = 0; i < n; i++ )
	{
		cin >> arr[ i ];
	}

	stack<int> seq;
	vector<char> cSeq;

	int j = 0;

	for( int i = 1; i <= n; i++ )
	{
		seq.push( i );
		cSeq.push_back( '+' );

		while( j < n && !seq.empty() && seq.top() == arr[ j ] )
		{
			seq.pop();
			cSeq.push_back( '-' );
			j++;
		}
	}

	if( seq.empty() )
	{
		for( int i = 0; i < cSeq.size(); i++ )
		{
			cout << cSeq[ i ] << '\n';
		}
	}
	else
	{
		cout << "NO" << endl;
	}

	free( arr );

	return 0;
}