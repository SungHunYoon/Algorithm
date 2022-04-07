#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int min_value = arr[ 0 ];
    int min_index = 0;
    for( int i = 1; i < arr.size(); i++ )
    {
        if( min_value > arr[ i ] )
        {
            min_value = arr[ i ];
            min_index = i;
        }
    }
    
    arr.erase( arr.begin() + min_index );
    
    if( arr.empty() ) arr.push_back( -1 );
    
    answer = arr;
    
    return answer;
}