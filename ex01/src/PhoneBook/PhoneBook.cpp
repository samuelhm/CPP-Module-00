/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:00:20 by shurtado          #+#    #+#             */
/*   Updated: 2025/02/02 15:41:41 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	last_index = -1;
}

PhoneBook::PhoneBook(const PhoneBook &phoneBook)
{
	copyContacts(phoneBook.contacts);
}

PhoneBook& PhoneBook::operator=(const PhoneBook &phoneBook)
{
	if (this != &phoneBook)
		copyContacts(phoneBook.contacts);
	return (*this);
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::copyContacts(const Contact *contacts)
{
	for (int i = 0; i < 6; i++)
		this->contacts[i] = contacts[i];
}

void	PhoneBook::addContact(const Contact &contact)
{
	if (last_index == 7)
		last_index = 0;
	else
		last_index++;
	contacts[last_index] = contact;
}

void	PhoneBook::deleteContact(const int &index)
{
	if (index < 0 || index > 7)
		return ;
	Contact contact;
	contacts[last_index] = contact;
}

Contact&	PhoneBook::getContact(const int &index)
{
	return (contacts[index]);
}
