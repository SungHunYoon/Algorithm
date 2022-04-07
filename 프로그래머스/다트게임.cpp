#include <cmath>
#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    int check[ 3 ];
    int index = 0;
	string score;
	for( int i = 0; i < dartResult.length(); i++ )
	{
		switch( dartResult[ i ] )
		{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			score += dartResult[ i ];
			break;

			case '#':
			check[ index - 1 ] *= -1;
			break;
			case '*':
			if( index - 2 >= 0 )
				check[ index - 2 ] *= 2;
			check[ index - 1 ] *= 2;
			break;

			case 'S':
			check[ index++ ] = pow( stoi( score ), 1 );
			score.clear();
			break;
			case 'D':
			check[ index++ ] = pow( stoi( score ), 2 );
			score.clear();
			break;
			case 'T':
			check[ index++ ] = pow( stoi( score ), 3 );
			score.clear();
			break;

		}
	}
    
    answer = check[ 0 ] + check[ 1 ] + check[ 2 ];
    
    return answer;
}