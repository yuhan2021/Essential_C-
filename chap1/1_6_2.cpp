#include <iostream>
using namespace std;

int main() 
{
    const int array_size = 128;
    int ia[array_size];
    int icnt = 0, ival = 0, sum = 0;
    while (icnt < array_size && cin >> ival)
        ia[icnt++] = ival;
    
    for (int ix = 0; ix < icnt; ++ix)
        sum += ia[ix];
    int avg = sum/icnt;

    cout << "sum of " << array_size << " elements: " << sum << ". "
        << "Average: " << avg << endl;    

    return 0;
}