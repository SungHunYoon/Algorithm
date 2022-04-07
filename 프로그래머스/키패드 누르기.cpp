#include <string>
#include <vector>

using namespace std;

int move_check( int pos, int target )
{
	int result = 0;
    
	while( target != pos )
	{
		if( target >= pos + 3 )
		{
			result += 1;
			pos += 3;
		}
        else if( target <= pos - 3 )
		{
			result += 1;
			pos -= 3;
		}
		else if( target >= pos + 1 )
		{
			result += 1;
			pos += 1;
		}

		else if( target <= pos - 1 )
		{
			result += 1;
			pos -= 1;
        }
	}

	return result;
}

string solution( vector<int> numbers, string hand ) {
	string answer = "";

	int left_pos = 10;
	int right_pos = 12;

	int left_move = 0;
	int right_move = 0;

	for( int i = 0; i < numbers.size(); i++ )
	{
        if( numbers[ i ] == 0 ) numbers[ i ] = 11;
        
		if( numbers[ i ] == 1 || numbers[ i ] == 4 || numbers[ i ] == 7 )
		{
			answer += "L";
			left_pos = numbers[ i ];
		}
		else if( numbers[ i ] == 3 || numbers[ i ] == 6 || numbers[ i ] == 9 )
		{
			answer += "R";
			right_pos = numbers[ i ];
		}
		else
		{
			left_move = move_check( left_pos, numbers[ i ] );
			right_move = move_check( right_pos, numbers[ i ] );

			if( left_move > right_move )
			{
				answer += "R";
				right_pos = numbers[ i ];
			}
			else if( right_move > left_move )
			{
				answer += "L";
				left_pos = numbers[ i ];
			}
			else
			{
				if( hand == "right" )
				{
					answer += "R";
					right_pos = numbers[ i ];
				}
				else
				{
					answer += "L";
					left_pos = numbers[ i ];
				}
			}
		}
	}

	return answer;
}