#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int space_index = 0;
    for( int i = 0; i < s.length(); i++ )
    {
        if( s.at( i ) == ' ' )
        {
            space_index = 0;
            continue;
        }
        
        if( space_index % 2 == 0 ) s.at( i ) = toupper( s.at( i ) );
        else s.at( i ) = tolower( s.at( i ) );
        
        space_index++;
    }
    
    answer = s;
    
    return answer;
}