/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:23:19 by shurtado          #+#    #+#             */
/*   Updated: 2024/11/07 01:46:15 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

#define DEFAULT_MESSAGE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << DEFAULT_MESSAGE << std::endl;
        return (0);
    }
    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j] != '\0' ; j++)
        {
            std::cout << (char)toupper(argv[i][j]);
        }
        std::cout << " ";
    }
    std::cout << std::endl;
    return (0);
}