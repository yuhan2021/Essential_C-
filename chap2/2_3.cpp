#include <iostream>
#include <vector>
using namespace std;

void calc_elements( vector<int> &vec, int pos );
void disp_elements( vector<int> &vec, const string &title);
inline bool is_valid_calc( vector<int> &vec, int pos );

int main()
{
    vector<int> pent;
    const string title ( "Pentagonal Numeric Series" );
    
    if ( is_valid_calc( pent, 0 ) )
    {
        disp_elements( pent, title );
    }
        
    
    if ( is_valid_calc( pent, 8) )
        disp_elements( pent, title );
    
    if ( is_valid_calc( pent, 16) )
        disp_elements( pent, title );

    if ( is_valid_calc( pent, 137) )
        disp_elements( pent, title );

    return 0;
}


void calc_elements( vector<int> &vec, int pos )
{
    for ( int ix = vec.size()+1; ix <= pos; ++ix )
    {
        vec.push_back( ix * (3 * ix - 1) / 2 );
    }
}

void disp_elements( vector<int> &vec, const string &title)
{
    cout << title << endl;
    for ( int ix = 0; ix < vec.size(); ++ix )
    {
        cout << vec[ix] << " ";
    }
    cout << endl;
}

bool is_valid_calc( vector<int> &vec, int pos )
{
    if ( pos <= 0 || pos > 64 )
    {
        cerr << "Sorry. Invalid position: " << pos << endl;
        return false;
    }

    if ( vec.size() < pos )
    {
        calc_elements( vec, pos );
    }
    return true;
}
