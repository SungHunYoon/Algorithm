#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    int start;
    int end;
    
    if( a >= b )
    {
        start = b;
        end = a;
    }
    else
    {
        start = a;
        end = b;
    }
    
    for( ; start <= end; start++ )
        answer += start;
    
    return answer;
}