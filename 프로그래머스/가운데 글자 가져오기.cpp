#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int pos;
    int count;
    
    if( s.length() % 2 == 0 )
    {
        pos = s.length() / 2 - 1;
        count = 2;
    }
    else
    {
        pos = s.length() / 2;
        count = 1;
    }
        
    answer = s.substr( pos, count );
    
    return answer;
}