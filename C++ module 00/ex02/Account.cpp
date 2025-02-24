#include <iostream>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void ){
    time_t timestamp = time(NULL);
    struct tm *datetime = localtime(&timestamp);
    char output[50];

    strftime(output, 50, "[%Y%m%d_%I%M%S] ", datetime);
    std::cout << output;
}

Account::Account( int initial_deposit ){
    
    this->_accountIndex = Account::_nbAccounts++;
    this->_amount = initial_deposit;
    Account::_totalAmount += this->_amount;
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex 
                << ";amount:" << _amount 
                << ";created" << std::endl;
}

Account::~Account(){
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex 
                << ";amount:" << _amount 
                << ";closed" << std::endl;
}

void	Account::displayAccountsInfos( void ){
    _displayTimestamp();
    std::cout   << "accounts:" << _nbAccounts 
                << ";total:" << _totalAmount 
                << ";deposits:" << _totalNbDeposits 
                << ";withdrawals:" << _totalNbWithdrawals 
                << std::endl;

}

void	Account::displayStatus( void ) const{
   _displayTimestamp();
    std::cout   << "index:" << _accountIndex 
                << ";amount:" << _amount 
                << ";deposits:" << _nbDeposits 
                << ";withdrawals:" << _nbWithdrawals
                << std::endl;
}

int		Account::checkAmount( void ) const{
    return (this->_amount);
}

void	Account::makeDeposit( int deposit ){
    int p_amount = this->_amount;
    this->_amount += deposit;
    Account::_totalAmount += deposit;
    this->_nbDeposits++;
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex 
                << ";p_amount:" << p_amount 
                << ";deposit:" << deposit 
                << ";amount:" << _amount 
                << ";nb_deposit:" << _nbDeposits 
                << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
    int p_amount = this->_amount;

    if (this->_amount < withdrawal){
        _displayTimestamp();
        std::cout   << "index:" << _accountIndex
                    << ";p_amout:" << p_amount
                    << ";withrawal:refused"
                    << std::endl;
        return (false);
    }
    Account::_totalAmount -= withdrawal;
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex
                << ";p_amout:" << p_amount
                << ";withrawal:" << withdrawal
                << ";amount:" << _amount
                << ";nb_withdrawals:" << _nbWithdrawals
                << std::endl;
    return (true);
}

	int	Account::getNbAccounts( void ){
        return(_nbAccounts);
    }

    int	Account::getTotalAmount( void ){
        return (_totalAmount);
    }

    int	Account::getNbDeposits( void ){
        return (_totalNbDeposits);
    }

    int	Account::getNbWithdrawals( void ){
        return (_totalNbWithdrawals);
    }
