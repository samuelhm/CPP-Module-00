/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:52:55 by shurtado          #+#    #+#             */
/*   Updated: 2025/02/02 21:00:27 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalAmount = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void)
{
	this->_accountIndex = Account::getNbAccounts();
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = 0;
	Account::_nbAccounts++;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::getNbAccounts();
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = initial_deposit;
	Account::_nbAccounts++;

	Account::_totalAmount += this->_amount;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount <<";created" << std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	Account::_totalAmount -= this->_amount;
	Account::_totalNbDeposits -= this->_nbDeposits;
	Account::_totalNbWithdrawals -= this->_nbWithdrawals;
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t	now;
	tm		*ltm;

	now = time(0);
	ltm = localtime(&now);

	std::cout << "[" << 1900 + ltm->tm_year << std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon << std::setw(2) << std::setfill('0') << ltm->tm_mday \
				<< "_" << ltm->tm_hour << ltm->tm_min << ltm->tm_sec << "]";
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{

	Account::_displayTimestamp();
	std::cout	<< " accounts:"<< Account::getNbAccounts() << ";total:" << Account::getTotalAmount() \
				<< ";deposits:" << Account::getNbDeposits() << ";withdrawals:" \
				<< Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	this->_nbDeposits++;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit \
				<< ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" \
				<< this->_nbDeposits << std::endl;

}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout <<" index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	if (this->_amount - withdrawal < 0)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		std::cout << ";withdrawal:" << withdrawal;
		std::cout << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
