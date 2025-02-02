/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:00:18 by shurtado          #+#    #+#             */
/*   Updated: 2025/02/02 20:36:28 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "../Contact/Contact.hpp"

class	PhoneBook
{
	private:
		Contact contacts[8];
		void	copyContacts(const Contact contacts[]);
		int		last_index;

	public:
		PhoneBook();
		PhoneBook(const PhoneBook &phoneBook);
		PhoneBook& operator=(const PhoneBook &phoneBook);
		~PhoneBook();

		void		addContact(const Contact &contact);
		void		deleteContact(const int &index);
		Contact&	getContact(const int &index);
};

#endif
