
#include "easyfind.hpp"

int main()
{
    int myints[] = { 10, 20, 30, 40 };
    std::array<int , 4> myarray = { 10, 20, 30, 40 };
    std::vector<int> myvector ( myints, myints+4 );

try
{
    int num1 = easyfind( myarray, 20 );
    std::cout << "array: " << num1 << std::endl;
}
catch (std::out_of_range &e)
{
	std::cout << e.what() << std::endl;
}

try
{
    int num2 = easyfind(myvector, 50);
    std::cout << "vector: " << num2 << std::endl;
}
catch (std::out_of_range &e)
{
	std::cout << e.what() << std::endl;
}
    return 0;
}