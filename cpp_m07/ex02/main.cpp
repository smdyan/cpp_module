#include <iostream>
#include "Array.hpp"

int main()
{
    // Empty
	std::cout << std::endl << "test Empty array" << std::endl;
	Array<int>	arr;
	try
	{
		std::cout << "Acessing element 0: " << arr[0] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}

	// INT
	std::cout << std::endl << "Int array" << std::endl;
	std::cout << "----------------------------" << std::endl;
	Array<int> narr(4);
	std::cout << "Before assigning: \n" << narr << std::endl;
	narr[0] = 8;
	narr[1] = 2;
	narr[2] = -64;
	narr[3] = 248;
	std::cout << "After assigning: \n" << narr << std::endl;

    	// STRING
	std::cout << std::endl << "String array" << std::endl;
	std::cout << "----------------------------" << std::endl;
	Array<std::string> sarr(4);
	std::cout << "Before assigning: \n" << sarr << std::endl;
	sarr[0] = "First string";
	sarr[1] = "Second string";
	sarr[2] = "Third string";
	sarr[3] = "Fourth string";
	std::cout << "After assigning: \n" << sarr << std::endl;


    return 0;
}