#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    vector<int> complete;
    vector<int> time( truck_weights.size() );
    int run_start = 0;
    int run_end = 0;
    int run_weight = 0;
    
    while( complete.size() < truck_weights.size() )
    {
        answer++;
        for( int i = run_start; i < run_end; i++ )
        {
            time[ i ]++;
            if( bridge_length <= time[ i ] ) 
            {
                run_weight -= truck_weights[ i ];
                run_start++;
                complete.push_back( truck_weights[ i ] );
            }
        }
        
        if( run_end < truck_weights.size() && weight >= run_weight + truck_weights[ run_end ] )
        {
            run_weight += truck_weights[ run_end ];
            run_end++;
        }
        
    }
    
    return answer;
}