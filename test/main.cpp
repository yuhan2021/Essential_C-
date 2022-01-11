#include <iostream>
#include "util_load.h"

int main(){
    util_load m_load;
    std::string path = m_load.get_path();
    std::cout << path << std::endl;

    return 0;
}