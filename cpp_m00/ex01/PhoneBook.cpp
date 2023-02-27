/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:32:33 by smdyan            #+#    #+#             */
/*   Updated: 2022/09/09 20:32:40 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(){
    index = 0;
    lines = 0;
    stop = 0;
    n = 0;
    memset(array, 0, 8 * sizeof (Contact));
}
PhoneBook::~PhoneBook()
{}

void    PhoneBook::add(){
    std::cout << "Enter a first name: ";
    std::cin >> txt;
    array[index].setFname(txt);
    std::cout << "Enter a last name: ";
    std::cin >> txt;
    array[index].setLname(txt);
    std::cout << "Enter a nickname: ";
    std::cin >> txt;
    array[index].setNname(txt);
    std::cout << "Enter a phone number: ";
    std::cin >> txt;
    array[index].setPnum(txt);
    std::cout << "Enter a secret: ";
    std::cin >> txt;
    array[index].setSecret(txt);
    index++;
    if (index >= 8)
        index = 0;
    if (lines < 8)
        lines++;
}

void    PhoneBook::search(){
    displayBook();
    std::cout << "Enter an index: ";
    n = 0;
    stop = 0;
    if (!lines)
    {
        stop = 1;
        std::cout << "n/a" << std::endl;
    }
    while (!stop)
    {
        std::cin >> txt;
        try{
            n = stoi(txt, nullptr);
        if (0 < n && n <= lines)
            stop = 1;
        else
            std::cout << "1:wrong value" << std::endl;
        }
        catch (std::exception ex){
            std::cout << "2:wrong value" << std::endl;
        }
    }
    displayContact(n - 1);
}

void    PhoneBook::displayBook(){
    n = 0;
    while (n < lines)
    {
        std::cout << "         " << n + 1 << "|";
        std::cout << array[n].getColumn(0) << "|";
        std::cout << array[n].getColumn(1) << "|";
        std::cout << array[n].getColumn(2) << std::endl;
        n++;
    }
}

void    PhoneBook::displayContact(int n){
        if (n >= 0)
        {
            std::cout << array[n].getField(0) << std::endl;
            std::cout << array[n].getField(1) << std::endl;
            std::cout << array[n].getField(2) << std::endl;
            std::cout << array[n].getField(3) << std::endl;
            std::cout << array[n].getField(4) << std::endl;
        }
}