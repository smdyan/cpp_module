/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:35:26 by smdyan            #+#    #+#             */
/*   Updated: 2022/09/09 20:35:29 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
    private:
        Contact     array[8];
        int         index;
        int         lines;
        int         n;
        int         stop;
        std::string txt;
        void        displayBook();
        void        displayContact(int n);

    public:
        PhoneBook();
        ~PhoneBook();
        void    add();
        void    search();
};

#endif
