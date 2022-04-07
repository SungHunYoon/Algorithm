#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> eratostenes( n + 1 );
    
    for( int i = 2; i <= n; i++ )
    {
        if( !eratostenes[ i ]  ) answer++;
        
        for( int j = i; j <= n; j += i )
            eratostenes[ j ] = true;
    }
    
    return answer;
}