/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:06:56 by shurtado          #+#    #+#             */
/*   Updated: 2025/02/02 20:19:24 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_HPP
#define MENU_HPP

#include <cstdlib>
#include <limits>
#include <sstream>
#include <iostream>
#include <string>
#include "../Contact/Contact.hpp"
#include "../PhoneBook/PhoneBook.hpp"

namespace Menu
{
	extern int option;

	void		Mostrar(PhoneBook &phoneBook);
	void		Frame(const std::string &texto);
	void		FrameTittle(const std::string &texto);
	int			GetOption();
	int			GetContactIndex();
	void		ShowMainMenu();
	void		AddContactMenu(PhoneBook &phoneBook);
	void		SearchMenu(PhoneBook &phoneBook);
	bool		CheckNumbers(const std::string &number);
	std::string	AddStringValue(const std::string &type);
	int			ContactsAvailable(PhoneBook &phoneBook);
	void		FrameContact(int count, PhoneBook &phoneBook);
	void		PrintContact(Contact contact);
}

#endif // MENU_HPP
