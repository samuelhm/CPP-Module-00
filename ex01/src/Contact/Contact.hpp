/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:11:24 by shurtado          #+#    #+#             */
/*   Updated: 2025/02/02 14:55:07 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

typedef std::string string_t;

class	Contact
{
	private:
		string_t	nickname;
		string_t	name;
		string_t	lastname;
		string_t	phonenumber;
		string_t	darksecret;

	public:
		Contact();
		Contact(const string_t &nickName, const string_t &name, \
				const string_t &lastName, const string_t &phoneNumber, \
				const string_t &darkSecret);
		Contact(const Contact &contact);
		Contact& operator=(const Contact &contact);
		~Contact();

		void		setNickName(const string_t &nickName);
		void		setName(const string_t &name);
		void		setLastName(const string_t &lastName);
		void		setPhoneNumber(const string_t &phoneNumber);
		void		setDarkSecret(const string_t &darkSecret);

		string_t	getNickName() const;
		string_t	getName() const;
		string_t	getLastName() const;
		string_t	getPhoneNumber() const;
		string_t	getDarkSecret() const;
};

#endif
