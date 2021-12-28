#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int ival;
    vector<int> ivec;
    while (cin >> ival)
        ivec.push_back(ival);

    int sum = 0;
    for (int ix = 0; ix < ivec.size(); ++ix)
        sum += ivec[ix];

    int avg = sum / ivec.size();
    cout << "sum of " << ivec.size() << " elements: " << sum << ". "
        << "Average: " << avg << endl;

    return 0;
}