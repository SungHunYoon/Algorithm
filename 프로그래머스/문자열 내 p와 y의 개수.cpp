#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    int p_count = 0;
    int y_count = 0;
    
    for( int i = 0; i < s.length(); i++ )
    {
        if( tolower( s.at( i ) ) == 'y' ) y_count++;
        else if( tolower( s.at( i ) ) == 'p') p_count++;
    }
    
    if( y_count != p_count ) answer = false;
    
    return answer;
}