#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    set<int> st;
    
    for( int i = 0; i < nums.size(); i++ )
    {
        st.insert( nums[ i ] );
    }
    
    //return nums.size() / 2 - st.size();
    
    if( (int)( nums.size() / 2 - st.size() ) > 0 )
        answer = st.size();
    else
        answer = nums.size() / 2;
    
    return answer;
}