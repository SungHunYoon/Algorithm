#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    
    long lnum = num;
    while( lnum != 1 )
    {
        if( lnum % 2 == 0 )
        {
            lnum /= 2;
        }
        else
        {
            lnum *= 3;
            lnum += 1;
        }
        answer++;
        if( answer >= 500 ) return -1;
    }
    
    return answer;
}