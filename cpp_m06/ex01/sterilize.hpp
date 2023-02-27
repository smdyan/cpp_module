#ifndef STERILIZE_HPP
# define STERILIZE_HPP

#include <stdint.h>
#include <iostream>

struct Data
{
	std::string data;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif