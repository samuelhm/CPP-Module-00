/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:25:43 by shurtado          #+#    #+#             */
/*   Updated: 2025/02/02 14:58:34 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	setNickName("");
	setName("");
	setLastName("");
	setPhoneNumber("");
	setDarkSecret("");
}

Contact::Contact(const string_t &nickName, const string_t &name, \
				 const string_t &lastName, const string_t &phoneNumber, \
				 const string_t &darkSecret)
{
	setNickName(nickName);
	setName(name);
	setLastName(lastName);
	setPhoneNumber(phoneNumber);
	setDarkSecret(darkSecret);
}
Contact::Contact(const Contact &contact)
{
	setNickName(contact.getNickName());
	setName(contact.getName());
	setLastName(contact.getLastName());
	setPhoneNumber(contact.getPhoneNumber());
	setDarkSecret(contact.getDarkSecret());
}
Contact& Contact::operator=(const Contact &contact)
{
	if(this != &contact)
	{
		this->setNickName(contact.getNickName());
		this->setName(contact.getName());
		this->setLastName(contact.getLastName());
		this->setPhoneNumber(contact.getPhoneNumber());
		this->setDarkSecret(contact.getDarkSecret());
	}
	return (*this);
}

Contact::~Contact()
{

}

void Contact::setNickName(const string_t &nickName)
{
	this->nickname = nickName;
}

void Contact::setName(const string_t &name)
{
	this->name = name;
}

void Contact::setLastName(const string_t &lastName)
{
	this->lastname = lastName;
}

void Contact::setPhoneNumber(const string_t &phoneNumber)
{
	this->phonenumber = phoneNumber;
}

void Contact::setDarkSecret(const string_t &darkSecret)
{
	this->darksecret = darkSecret;
}

string_t Contact::getNickName() const
{
	return this->nickname;
}

string_t Contact::getName() const
{
	return this->name;
}

string_t Contact::getLastName() const
{
	return this->lastname;
}

string_t Contact::getPhoneNumber() const
{
	return this->phonenumber;
}

string_t Contact::getDarkSecret() const
{
	return this->darksecret;
}
