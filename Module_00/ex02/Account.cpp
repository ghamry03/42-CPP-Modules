#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <time.h>

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
	this->_accountIndex = Account::getNbAccounts();
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->checkAmount() << ";created" << std::endl;
	return ;
}

Account::~Account( void ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" 
		<< this->checkAmount()	<< ";closed" << std::endl;
	Account::_nbAccounts--;	return ;
}

void	Account::_displayTimestamp( void ) {
	time_t		currentTime;
	tm			*localTime;

	currentTime = time(NULL);
	localTime = localtime(&currentTime);
//	std::cout << std::put_time(localTime, "[%Y%m%d_%H%M%S] ");
	std::cout << '[' << localTime->tm_year + 1900 << localTime->tm_mon << localTime-> tm_mday
		<< "_" << localTime->tm_hour << localTime->tm_min << localTime->tm_sec << "] ";
}

int		Account::getNbAccounts ( void ) {
	return (Account::_nbAccounts);
}

int		Account::getTotalAmount( void ) {
	return (Account::_totalAmount);
}

int		Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

int		Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:"
		<< Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits()
		<< ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
	return ;
}

void	Account::makeDeposit( int deposit ) {
	int		pAmount;

	pAmount = this->checkAmount();  
	this->_nbDeposits++;
	this->_amount += deposit;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << pAmount 
		<< ";deposit:" << deposit << ";amount:" << this->checkAmount()  
		<< ";nb_deposits:" << this->_nbDeposits << std::endl;
	return ;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	int		pAmount;

	pAmount = this->checkAmount();
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << pAmount
		<< ";withdrawal:";
	if (withdrawal > this->checkAmount()) {
		std::cout << "refused" << std::endl;
		return (false);
	} else {
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		std::cout << withdrawal << ";amount:" << this->checkAmount()
			<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
}

int		Account::checkAmount( void ) const {
	return (this->_amount);
}

void	Account::displayStatus ( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->checkAmount() << ";deposits:"
		<< this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals
		<< std::endl;
	return ;
}
