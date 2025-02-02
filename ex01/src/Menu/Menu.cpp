/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:52:29 by shurtado          #+#    #+#             */
/*   Updated: 2025/02/02 20:22:40 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Menu.hpp"

static std::string formatField(const std::string &str)
{
	std::string	result;
	if (str.size() > 10)
	{
		return str.substr(0, 9) + ".";
	}
	result = str;
	result.insert(result.begin(), 10 - result.size(), ' ');
	return (result);
}

namespace Menu
{
	int		option;
	void	ShowMainMenu()
	{
		std::system("clear");
		Menu::FrameTittle("Welcome to Shurtado's Phonebook.");
		Menu::Frame("ADD - to add a contact");
		Menu::Frame("SEARCH - to show contact list");
		Menu::Frame("EXIT - :(");
		std::cout << std::endl << "Selecciona una opción: ";
		std::cout << "\033[J";
	}

	void	Mostrar(PhoneBook &phoneBook)
	{
		if (option == 0)
		{
			ShowMainMenu();
			while (true)
			{
				option = GetOption();
				if (option > 0)
					break;
			}
		}
		else if (option == 1)
			AddContactMenu(phoneBook);
		else if (option == 2)
			SearchMenu(phoneBook);
	}

	int	ContactsAvailable(PhoneBook &PhoneBook)
	{
		for (int i = 0; i < 7; i++)
			if (PhoneBook.getContact(i).getName() == "")
				return (i);
		return (8);
	}

	void	SearchMenu(PhoneBook &phoneBook)
	{
		int	count;
		int	cindex;
		count = ContactsAvailable(phoneBook);
		if (count == 0)
		{
			std::cout << "\033[A\033[K\033[91mError, No contacts\033[0m" << std::endl;
			std::cin.get();
			std::cin.clear();
			option = 0;
			return ;
		}
		std::system("clear");
		Menu::FrameTittle("Contact List");
		Menu::FrameContact(count, phoneBook);
		std::cout << std::endl << "Selecciona un contacto: ";
		std::cout << "\033[J";
		do
		{
			cindex = GetContactIndex();
		} while (cindex > count || cindex < 0);
		PrintContact(phoneBook.getContact(cindex));
		std::cin.get();
		std::cin.clear();
		option = 0;
	}

	void	PrintContact(Contact contact)
	{
		std::cout << "First Name:     " << contact.getName()    << std::endl;
		std::cout << "Last Name:      " << contact.getLastName()     << std::endl;
		std::cout << "Nickname:       " << contact.getNickName()     << std::endl;
		std::cout << "Phone Number:   " << contact.getPhoneNumber()  << std::endl;
		std::cout << "Darkest Secret: " << contact.getDarkSecret() << std::endl;
	}
	void	AddContactMenu(PhoneBook &phoneBook)
	{
		Contact contact;
		std::system("clear");
		Menu::FrameTittle("Adding a contact!");
		contact.setNickName(AddStringValue("Nick Name"));
		contact.setName(AddStringValue("Name"));
		contact.setLastName(AddStringValue("Last Name"));
		contact.setPhoneNumber(AddStringValue("Phone Number"));
		contact.setDarkSecret(AddStringValue("Dark Secret"));
		phoneBook.addContact(contact);
		option = 0;

	}

	bool	CheckNumbers(const std::string &s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			if (!std::isdigit(static_cast<unsigned char>(s[i])))
				return false;
		}
		return true;
	}

	std::string	AddStringValue(const std::string &type)
	{
		std::cout << "Insert "<< type <<": ";
		std::string line;
		while (true)
		{
			if (!std::getline(std::cin, line))
			{
				std::cin.clear();
				continue ;
			}
			if(line.empty() || (type == "Phone Number" && !CheckNumbers(line)))
			{
				std::cout << "\033[A\033[KInsert " << type << ": " << "\033[J";
				continue;
			}
			else
				return (line);
		}
	}

	int	GetContactIndex()
	{
		std::string line;
		if (!std::getline(std::cin, line))
		{
			std::cin.clear();
			return (-1);
		}
		if (line.size() == 1 && line[0] >= '0' && line[0] <= '7')
		{
			int index = line[0] - '0';
			return (index);
		}
		else
		{
			std::cout << "\033[A\033[KSelecciona un contacto: " << "\033[J";
			return (-1);
		}
	}
	int	GetOption()
	{
		std::string line;
		if (!std::getline(std::cin, line))
		{
			std::cin.clear();
			return (-1);
		}
		if (line == "ADD")
			return (1);
		else if (line == "SEARCH")
			return (2);
		else if (line == "EXIT")
			return (3);
		else
		{
			std::cout << "\033[A\033[KSelecciona una opción: " << "\033[J";
			return (-1);
		}
	}

	void	Frame(const std::string &texto)
	{
		std::cout << "+" << std::string(texto.size() + 2, '-') << "+\n";
		std::cout << "| " << texto << " |\n";
		std::cout << "+" << std::string(texto.size() + 2, '-') << "+\n";
	}

	void	FrameTittle(const std::string &texto)
	{
		std::cout << "╔";
		for (size_t i = 0; i < texto.size() + 2; i++)
			std::cout << "═";
		std::cout << "╗\n";
		std::cout << "║ " << texto << " ║\n";
		std::cout << "╚";
		for (size_t i = 0; i < texto.size() + 2; i++)
			std::cout << "═";
		std::cout << "╝\n";
	}

void FrameContact(int count, PhoneBook &phoneBook)
	{
		const int columns = 4;
		const int colWidth = 10;
		int totalInnerWidth = columns * colWidth + (columns - 1);
		std::cout << "╔";
		for (int i = 0; i < totalInnerWidth; i++)
			std::cout << "═";
		std::cout << "╗\n";
		{
			std::string headers[4] = { "Index", "First Name", "Last Name", "Nickname" };
			std::cout << "║";
			for (int c = 0; c < columns; c++)
			{
				std::cout << "\033[1;92m" << formatField(headers[c]) << "\033[0m";
				if (c < columns - 1)
					std::cout << "|";
			}
			std::cout << "║\n";
		}
		for (int i = 0; i < count; i++)
		{
			Contact c = phoneBook.getContact(i);
			std::ostringstream oss;
			oss << i;
			std::string indexStr   = oss.str();
			std::string firstName  = c.getName();
			std::string lastName   = c.getLastName();
			std::string nickname   = c.getNickName();
			std::cout	<< "║";
			std::cout	<< formatField(indexStr)	<< "|"
						<< formatField(firstName)	<< "|"
						<< formatField(lastName)	<< "|"
						<< formatField(nickname);
			std::cout	<< "║\n";
		}

		std::cout << "╚";
		for (int i = 0; i < totalInnerWidth; i++)
			std::cout << "═";
		std::cout << "╝\n";
	}
}
