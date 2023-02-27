/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 23:12:25 by smdyan            #+#    #+#             */
/*   Updated: 2022/09/08 23:13:32 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	size_t i;
	std::string my_str;
	
	(void) argv; 
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	};
	i = 1;
	while ((int) i < argc)
	{
		my_str += argv[i];
		my_str += " ";
		i++;
	}
	i = 0;
	my_str.resize(my_str.size() - 1);
	while (i < my_str.size())
	{
		std::cout << (char) toupper(my_str.at(i));
		i++;
	}
	std::cout << std::endl;
	return (0);
}
