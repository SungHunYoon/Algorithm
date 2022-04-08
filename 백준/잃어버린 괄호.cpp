#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	string input;

	cin >> input;

	vector<int> number;
	vector<char> oper;

	string num = "";
	int index = 0;

	for( int i = 0; i < input.length(); i++ )
	{
		if( input[ i ] == '-' || input[ i ] == '+' )
		{
			number.push_back( stoi( input.substr( index, i ) ) );
			index = i;
			oper.push_back( input[ i ] );
			num = "";
		}
		else
		{
			num += input[ i ];
		}
	}
    number.push_back( stoi( input.substr( index, input.length() ) ) );

	/*
	while( input.length() > 0 )
	{
		if( input.find( '-' ) )
		{
			number.push_back( stoi( input.substr( 0, input.find( '-' ) ) ) );
			oper.push_back( input[ input.find( '-' ) ] );
			input.erase( 0, input.find( '-' ) );
		}
		else if( input.length() < input.find( '+' ) )
		{
			number.push_back( stoi( input.substr( 0, input.find( '-' ) ) ) );
			oper.push_back( input[ input.find( '+' ) ] );
			input.erase( 0, input.find( '+' ) );
		}
		else
		{
			number.push_back( stoi( input ) );
			input.erase( 0, input.end() );
		}
	}
	*/

	int n_oper = 1;
	int c_count = 0;
	int result = 0;

	for( int i = 0; i < number.size(); i++ )
	{
		if( number[ i ] > 0 )
			result += ( n_oper * number[ i ] );
		else
			result += number[ i ];
        
		if( number[ i ] < 0 )
			n_oper = -1;
	}

	cout << result << endl;

	//getchar();

	return 0;
}