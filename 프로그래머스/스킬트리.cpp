#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for( int i = 0; i < skill_trees.size(); i++ )
    {
        int skill_index = 0;
        bool isPossible = true;
        
        for( int j = 0; j < skill_trees[ i ].length(); j++ )
        {
            for( int k = skill_index; k < skill.length(); k++ )
            {
                if( skill_trees[ i ].at( j ) == skill.at( k ) )
                {
                    if( skill.at( skill_index ) != skill.at( k ) )
                    {
                        isPossible = false;   
                    }
                    else
                    {
                        skill_index++;
                    }
                }
            }
        }
        if( isPossible ) answer++;
    }
    
    return answer;
}