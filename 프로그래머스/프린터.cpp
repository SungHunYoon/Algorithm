#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    while( !priorities.empty() )
    {
        int check = 0;
        
        for( int i = 1; i < priorities.size(); i++ )
        {
            if( priorities[ 0 ] < priorities[ i ] )
            {
                check = 1;
                priorities.push_back( priorities[ 0 ] );
                priorities.erase( priorities.begin() );
                location--;
                if( location < 0 ) location = priorities.size() - 1;
                break;
            }
        }
            
        if( check == 0 )
        {
            answer++;
            priorities.erase( priorities.begin() );
            if( location == 0 ) break;
            location--;
        }
    }
    return answer;
}