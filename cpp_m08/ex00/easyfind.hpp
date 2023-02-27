#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector
#include <array>       // std::array

template < typename T>
int easyfind(T& t, int n)
{
	typename T::const_iterator it;
	it = std::find( t.begin(), t.end(), n );
	if( it == t.end() )
		throw(std::out_of_range("Element not found in given range"));
	else
		return *it;
}

#endif
