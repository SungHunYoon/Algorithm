#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc( const pair<int, double> &a, const pair<int, double> &b )
{
    if( a.second != b.second ) return a.second > b.second;
    else return a.first < b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    vector<int> count( N + 1 );
    
    for( int i = 0; i < stages.size(); i++ )
    {
        count[ stages[ i ] - 1 ] += 1;
    }
    
    vector<pair<int, double> > p;
    int user = stages.size();
    for( int i = 0; i < N; i++ )
    {
        if( count[ i ] != 0 )
            p.push_back( pair<int, double>( i, (double)count[ i ] / user ) );
        else
            p.push_back( pair<int, double>( i, 0 ) );
        user -= count[ i ];
    }
    
    sort( p.begin(), p.end(), desc );
    
    for( int i = 0; i < p.size(); i++ )
    {
        answer.push_back( p[ i ].first + 1 );
    }
    
    return answer;
}