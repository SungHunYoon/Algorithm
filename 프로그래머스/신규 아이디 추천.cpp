#include <string>
#include <vector>

using namespace std;

string first( string before_id )
{
    string after_id = "";
    
    for( int i = 0; i < before_id.length(); i++ )
    {
        if( before_id[i] >= 'A' && before_id[i] <= 'Z' )
            before_id[i] += 32;
    }
    
    after_id = before_id;
    
    return after_id;
}

string second( string before_id )
{
    string after_id = "";
    
    for( int i = 0; i < before_id.length(); i++ )
    {
        if( ( before_id[i] >= 'a' && before_id[i] <= 'z' ) ||
            ( before_id[i] >= '0' && before_id[i] <= '9' ) || 
            ( before_id[i] == '-' ) ||
            ( before_id[i] == '_' ) ||
            ( before_id[i] == '.' ) )
        {
            after_id += before_id[i];
        }
        /*
        else
        {
            after_id += ' ';
        }
        */
    }
    
    return after_id;
}

string third( string before_id )
{
    string after_id = "";
    
    int c_count = 0;
    
    for( int i = 0; i < before_id.length(); i++ )
    {
        if( before_id[i] == '.' )
        {
            if( c_count == 0 )
            {
                after_id += before_id[i];
            }
            /*
            else
            {
                after_id += ' ';
            }
            */
            c_count++;
        }
        else
        {
            c_count = 0;
            after_id += before_id[i];
        }
    }
    
    return after_id;
}

string fourth( string before_id )
{
    string after_id = "";
    
    int s_copy_index = 0, e_copy_index = before_id.length() - 1;
    
    if( before_id[ 0 ] == '.' )
    {
        s_copy_index += 1;
        //e_copy_index -= 1;
    }
    
    if( before_id[ e_copy_index ] == '.' )
        e_copy_index -= 1;
    
    //strncpy( after_id, before_id + s_copy_index, e_copy_index );
    for( int i = s_copy_index; i < e_copy_index + 1; i++ )
        after_id += before_id[ i ];
    
    return after_id;
}

string fifth( string before_id )
{
    string after_id = before_id;
    
    if( after_id == "" )
        after_id += 'a';
    
    return after_id;
}

string sixth( string before_id )
{
    string after_id = "";
    
    if( before_id.length() >= 16 )
    {
        //strncpy( after_id, before_id, 15 );
        for( int i = 0; i < 15; i++ )
            after_id += before_id[ i ];
        
        if( after_id[ after_id.length() - 1 ] == '.' )
            after_id.erase( after_id.length() - 1 );
    }
    else
    {
        after_id = before_id;
    }
    
    return after_id;
}

string seventh( string before_id )
{
    string after_id = before_id;

    while( after_id.length() <= 2 )
    {
        after_id += after_id[ after_id.length() - 1 ];
    }
    
    return after_id;
}

string solution(string new_id) {
    string answer = "";
    
    answer = first( new_id );
    answer = second( answer );
    answer = third( answer );
    answer = fourth( answer );
    answer = fifth( answer );
    answer = sixth( answer );
    answer = seventh( answer );
    
    return answer;
}