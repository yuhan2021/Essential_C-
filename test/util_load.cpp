#include <unistd.h>
#include "util_load.h"

std::string util_load::get_path()
{
    std::string path;
    char *buffer;

    if((buffer = getcwd(NULL, 0)) == NULL){
        std::cerr << "getcwd error" << std::endl;
    }
    else{
        std::cout << "path is: " << buffer << std::endl;
        free(buffer);
    }
}