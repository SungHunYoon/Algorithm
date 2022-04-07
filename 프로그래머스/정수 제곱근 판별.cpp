#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    for( long long i = 1; i <= sqrt(n); i++ )
    {
        if( i * i == n ) return ( i + 1 ) * ( i + 1 );
    }
    
    answer = -1;
    
    return answer;
}