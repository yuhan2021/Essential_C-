#include <iostream>
#include <vector>
using namespace std;

const vector<int>* pentagonal_series(int pos);

bool check_valid(int pos)
{
    return (pos <=0 || pos > 64) ? false : true;
}

bool pentagonal_elem(int pos, int &elem)
{
    if (!check_valid(pos))
    {
        cout << "Sorry. Invalid position: " << pos << endl;
        elem = 0;
        return false;
    }

    const vector<int> *pent = pentagonal_series(pos);
    elem = (*pent)[pos-1];
    return true;
}

const vector<int>* pentagonal_series(int pos)
{
    static vector<int> pen_vec;
    if (check_valid(pos) && pos > pen_vec.size())
    {
        for (int ix = pen_vec.size()+1; ix <= pos; ++ix)
            pen_vec.push_back((ix * (3 * ix-1 ))/2);
    }
    return &pen_vec;
}

int main()
{
    int elem;
    if (pentagonal_elem(8, elem))
        cout << "element 8 is " << elem << '\n';
    if (pentagonal_elem(88, elem))
        cout << "element 88 is " << elem << '\n';
    if (pentagonal_elem(12, elem))
        cout << "element 12 is " << elem << '\n';
    if (pentagonal_elem(64, elem))
        cout << "element 64 is " << elem << '\n';
    if (pentagonal_elem(0, elem))
        cout << "element 0 is " << elem << '\n';
    if (pentagonal_elem(-2, elem))
        cout << "element -2 is " << elem << '\n';
}
