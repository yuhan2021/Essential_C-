#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename Type>
inline Type mymax (Type t1, Type t2)
{
    return t1 > t2 ? t1 : t2;
}

template <typename Type_vec>
inline Type_vec max (const vector<Type_vec> &vec)
{
    return *max_element(vec.begin(), vec.end());
}

template <typename Type_arr>
inline Type_arr max (const Type_arr *arr, int size)
{
    return *max_element(arr, arr+size);
}

int main()
{
    string sarray[] = { "we", "were", "her", "pride", "of", "ten"};
    vector<string> svec(sarray, sarray+6);

    int iarray[] = {12, 70, 2, 169, 1, 5, 29};
    vector<int> ivec(iarray, iarray+7);

    float farray[] = {2.5, 24.8, 18.7, 4.1, 23.9};
    vector<float> fvec(farray, farray+5);

    int imax = mymax(max(ivec), max(iarray, 7));
    float fmax = mymax(max(fvec), max(farray, 5));
    string smax = mymax(max(svec), max(sarray, 6));

    cout << "imax should be 169 -- found: " << imax << '\n'
        << "fmax should be 24.8 -- found: " << fmax << '\n'
        << "smax should be were -- found: " << smax << '\n';

    std::string t = "";
    if (t.size() == 0)
        cout << "yes" <<endl;
}