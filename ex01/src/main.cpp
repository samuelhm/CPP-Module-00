/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:10:00 by shurtado          #+#    #+#             */
/*   Updated: 2025/02/02 19:17:05 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook/PhoneBook.hpp"
#include "Menu/Menu.hpp"

int main()
{
	PhoneBook myphonebook;
	do
	{
		Menu::Mostrar(myphonebook);
	} while (Menu::option != 3);
	return (0);
}
