#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

set<int> check_number;

bool isPrime( int number )
{  
    if( number < 2 ) return false;
    
    for( int i = 2; i * i <= number; i++ )
    {
        if( number % i == 0 ) return false;
    }
    
    return true;
}

void Combination( vector<int> arr, vector<int> comb, int r, int index, int depth )
{
	if( r == 0 )
	{
	    do
	    {
			int num = 0;
			string s_num = "";

			for( int i = 0; i < comb.size(); i++ )
			{
				s_num += to_string( comb[ i ] );
			}

			stringstream ssInt( s_num );
			ssInt >> num;

			check_number.insert( num );
	    } while( next_permutation( comb.begin(), comb.end() ) );
	}
	else if( arr.size() == depth ) return;
	else
	{
		comb[ index ] = arr[ depth ];
		Combination( arr, comb, r - 1, index + 1, depth + 1 );
		Combination( arr, comb, r, index, depth + 1 );
	}
}

int solution( string numbers ) {
	int answer = 0;

	vector<int> number;
	for( int i = 0; i < numbers.size(); i++ )
	{
		char a = numbers.at( i );
		number.push_back( atoi( &a ) );
	}

    sort( number.begin(), number.end() );
    
	for( int i = 0; i < numbers.size(); i++ )
	{
		vector<int> comb( i + 1 );
		Combination( number, comb, i + 1, 0, 0 );
	}

    set<int>::iterator iter;
    for(iter = check_number.begin(); iter != check_number.end(); iter++){
        if( isPrime( *iter ) ) answer++;
    }

	return answer;
}