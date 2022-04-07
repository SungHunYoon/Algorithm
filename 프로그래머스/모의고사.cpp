#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int check( vector<int> answers, vector<int> pick )
{
    int count = 0;
    
    int j = 0;
    for( int i = 0; i < answers.size(); i++ )
    {
        if( answers[ i ] == pick[ j ] )
        {
            count++;
        }
        j++;
        if( j >= pick.size() ) j = 0;
    }
    
    return count;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> first;
    vector<int> second;
    vector<int> third;
    
    first.push_back( 1 );
    first.push_back( 2 );
    first.push_back( 3 );
    first.push_back( 4 );
    first.push_back( 5 );
    
    second.push_back( 2 );
    second.push_back( 1 );
    second.push_back( 2 );
    second.push_back( 3 );
    second.push_back( 2 );
    second.push_back( 4 );
    second.push_back( 2 );
    second.push_back( 5 );
    
    third.push_back( 3 );
    third.push_back( 3 );
    third.push_back( 1 );
    third.push_back( 1 );
    third.push_back( 2 );
    third.push_back( 2 );
    third.push_back( 4 );
    third.push_back( 4 );
    third.push_back( 5 );
    third.push_back( 5 );
    
    int first_check = check( answers, first );
    int second_check = check( answers, second );
    int third_check = check( answers, third );
    
    int max_check = max( first_check, max( second_check, third_check ) );

	if( max_check == first_check ) answer.push_back( 1 );
	if( max_check == second_check ) answer.push_back( 2 );
	if( max_check == third_check ) answer.push_back( 3 );

    return answer;
}