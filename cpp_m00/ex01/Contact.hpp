/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:35:44 by smdyan            #+#    #+#             */
/*   Updated: 2022/09/09 21:18:54 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
    private:
        std::string array[5];
        std::string txt;

    public:
        Contact();
        ~Contact();
        void    setFname(std::string txt);
        void    setLname(std::string txt);
        void    setNname(std::string txt);
        void    setPnum(std::string txt);
        void    setSecret(std::string txt);
        std::string getField(int n);
        std::string getColumn(int n);
};

#endif