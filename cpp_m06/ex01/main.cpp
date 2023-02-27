#include <iostream>
#include "sterilize.hpp"

int main()
{
	Data d1;

	d1.data = "Hello world!";
	std::cout << "Initial data: " << &d1 << std::endl;
	std::cout << "Initial data value: " << d1.data << std::endl;
	uintptr_t raw = serialize(&d1);
	std::cout << "Raw data: " << raw << std::endl;
	Data *d2 = deserialize(raw);
	std::cout << "Deserialize data: " << d2 << std::endl;
	std::cout << "Deserialize data value: " << d2->data << std::endl;
	return (0);
}