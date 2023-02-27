#include "rep.hpp"

void    myrep(std::string &line, std::string &s1, std::string &s2)
{
    std::size_t len1 = s1.size();
    std::size_t len2 = s2.size();
    std::size_t pos(0);
    while (pos != std::string::npos)
    {
        pos = line.find(s1, pos);
        if (pos != std::string::npos)
        {
            line.erase(pos, len1);
            line.insert(pos, s2);
            pos += len2;
        }
    }
}