#include <iostream>
#include <string>
#include <vector>

using namespace std;

string number[ 10 ] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int solution( string s ) {
	int answer = 0;

	string str = "";
	for( int i = 0; i < 10; i++ )
	{
		while( s.find( number[ i ] ) != string::npos )
		{
			s.replace( s.find( number[ i ] ), number[ i ].length(), to_string(i) );
		}
	}

	answer = stoi( s );

	return answer;
}