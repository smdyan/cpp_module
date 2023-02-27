#include <iostream>
#include <fstream>
#include "rep.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Error: Bad parameter" << std::endl;
        return (1);
    }
    std::string filename1 = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream    file1;
    file1.open(filename1);
    std::string line;

    if (file1.is_open())
    {
        std::string filename2 = filename1 + ".replace";
        std::ofstream file2;
        file2.open(filename2);
        while (std::getline(file1, line))
        {
            myrep(line, s1, s2);
            file2 << line << std::endl;
        }
        file1.close();
        file2.close();
        std::cout << "Done" << std::endl;
    }
    else
    {
        std::cout << "Error: Failed to open file" << std::endl;
        return(1);
    }
    return (0); 
}