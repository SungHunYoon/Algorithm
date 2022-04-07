#include <string>
#include <vector>

using namespace std;

int solution( string s ) {
	int answer = 0;

	for( int i = 0; i < s.length(); i++ )
	{
		string s_answer = "";

		int index = 0;
		string pre_temp = s.substr( index, i + 1 );
		index += i + 1;

		int count = 0;
		while( index < s.length() )
		{
			string temp = s.substr( index, i + 1 );

			if( pre_temp == temp )
			{
				count += 1;
			}
			else
			{
				if( count > 0 ) s_answer += to_string( count + 1 );
				s_answer += pre_temp;

				count = 0;
			}

			pre_temp = temp;
			index += i + 1;
		}

		if( index > s.length() - ( i + 1 ) )
		{
			if( count > 0 ) s_answer += to_string( count + 1 );
			s_answer += s.substr( index - ( i + 1 ), i + 1 );

			count = 0;
		}

		//cout << s_answer << endl;

		if( answer == 0 ) answer = s_answer.length();
		else answer = answer > s_answer.length() ? s_answer.length() : answer;
	}

	return answer;
}