/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:45:29 by smdyan            #+#    #+#             */
/*   Updated: 2022/09/10 20:47:42 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main()
{
	int			stop;
	std::string	command;
	PhoneBook	MyBook;
	
	stop = 0;
	while (!stop)
	{
	std::cout << "Enter a command ADD, SEARCH or EXIT: ";
	std::cin >> command;
	if (command == "ADD")
	{
		MyBook.add();
	}
	else if (command == "SEARCH")
	{
		MyBook.search();
	}
	else if (command == "EXIT")
		stop = 1;
	}
	return (0);
}
