#include "Utils.h"

int get_depth(std::string line)
{
    int index = 0;

    while (line[index] == ' ')
        index++;

    return index;
}

std::string get_name(std::string line)
{
    std::string name = "";

    int depth = get_depth(line);
    size_t len = line.length();

    name = line.substr(depth, len);

    return name;
}