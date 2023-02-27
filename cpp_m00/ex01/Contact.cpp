/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:33:12 by smdyan            #+#    #+#             */
/*   Updated: 2022/09/09 20:33:16 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{}

Contact::~Contact()
{}

void    Contact::setFname(std::string txt){
    array[0] = txt;
}

void    Contact::setLname(std::string txt){
    array[1] = txt;
}

void    Contact::setNname(std::string txt){
    array[2] = txt;
}

void    Contact::setPnum(std::string txt){
    array[3] = txt;
}

void    Contact::setSecret(std::string txt){
    array[4] = txt;
}

std::string Contact::getField(int n){
    if (n >= 0 && n < 8)
        return (array[n]);
    else
        return ("error");
}

std::string Contact::getColumn(int n){
    txt = getField(n);
    if (txt.size() > 10)
    {
        txt.resize(9);
        txt.push_back('.');
    }
    while (txt.size() < 10)
        txt.insert(0, " ");
    return (txt);
}

