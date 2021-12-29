#include <iostream>
#include <vector>
using namespace std;

bool calc_elements( vector<int> &vec, int pos );
void disp_elements( vector<int> &vec, const string &title);

int main()
{
    vector<int> pent;
    const string title ( "Pentagonal Numeric Series" );
    
    if ( calc_elements( pent, 0 ) )
        disp_elements( pent, title );
    
    if ( calc_elements( pent, 8) )
        disp_elements( pent, title );
    
    if ( calc_elements( pent, 16) )
        disp_elements( pent, title );

    if ( calc_elements( pent, 137) )
        disp_elements( pent, title );

    return 0;
}

bool calc_elements( vector<int> &vec, int pos )
{
    if ( pos <= 0 || pos > 64 )
    {
        cerr << "Sorry. Invalid position: " << pos << endl;
        return false;
    }

    for ( int ix = vec.size()+1; ix <= pos; ++ix )
    {
        vec.push_back( ix * (3 * ix - 1) / 2 );
    }
    return true;
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
