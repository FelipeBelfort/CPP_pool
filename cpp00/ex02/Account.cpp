
#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount;
	std::cout << ";created" << std::endl;
}

Account::~Account(void)
{
	_nbAccounts--;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:";
	std::cout << this->_amount << ";closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

int	Account::checkAmount(void) const
{
	return this->_amount;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	this->_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";";
	this->_amount += deposit;
	std::cout << "deposit:" << deposit << ";amount:" << this->_amount;
	std::cout << ";nb_deposit:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	this->_amount -= withdrawal;
	std::cout << withdrawal << ";amount:" << this->_amount << ";nb_deposit:" << this->_nbDeposits << std::endl;
	return true;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:";
	std::cout << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:";
	std::cout << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t currentTime = std::time(NULL);
	struct std::tm *timeInfo = std::localtime(&currentTime);

	std::cout << "[" << std::put_time(timeInfo, "%Y%m%d_%H%M%S") << "]";
}
