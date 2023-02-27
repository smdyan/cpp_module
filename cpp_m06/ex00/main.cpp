
#include "Conversion.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Use single parameter" << std::endl;
		return (0);
	}
	try {
		Conversion a(argv[1]);
		a.transformation();
		std::cout << a << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}