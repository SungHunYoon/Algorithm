#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for( int i = 0; i < s.length(); i++ )
    {
        if( s.at( i ) >= 'a' && s.at( i ) <= 'z' )
        {
            unsigned char temp;
            temp = s.at( i ) + n;
            if( temp > 'z')
            {
                temp -= 'z';
                temp += 'a';
                temp -= 1;
            }
            answer += temp;
        }
        else if( s.at( i ) >= 'A' && s.at( i ) <= 'Z' )
        {
            unsigned char temp;
            temp = s.at( i ) + n;
            if( temp > 'Z' )
            {
                temp -= 'Z';
                temp += 'A';
                temp -= 1;
            }
            answer += temp;
        }
        else if( s.at( i ) == ' ' )
        {
            answer += ' ';
        }
    }
    return answer;
}