#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

int main()
{
    const int name_size = 128;
    char user_name[name_size];

    cout << "Please enter your name: ";
    cin >> setw(name_size) >> user_name;

    switch (strlen(user_name))
    {
        case 127:
            cout << "That is a very big name, indeed -- "
                << "we may have needed to shorten it!\n" 
                << "In any case, \n";

        default:
            cout << "Hello, " << user_name 
                << " -- happy to make your acquaintance!\n";
            break;
    }

    return 0;
}