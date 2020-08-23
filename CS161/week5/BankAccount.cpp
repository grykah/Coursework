/*************************************************************
** Author: Hailey Wilder
** 10/26/16
** Description: Provides bank information including name, ID,
** and balance.
**************************************************************/

#include <iostream>
#include <string>
#include "BankAccount.hpp"

using namespace std;


/***********************************************
** Name: BankAccount::BankAccount()
** Description: Default Constructor
** Parameters: Takes none. 
************************************************/
BankAccount::BankAccount()
{
	Name = "John Smith";
	ID = "TEST";
	Balance = 404.00;
}

/***********************************************
** Name: BankAccount::BankAccount()
** Description: BankAccount constructor with objects.
** Parameters: Objects Name, ID, and Balance with 
** appropriate params
************************************************/
BankAccount::BankAccount(string nam,string ident,double bal)
{
	Name = nam;
	ID = ident;
	Balance = bal;
}

/***********************************************
** Name: BankAccount::~BankAccount()
** Description: Destructor for BankAccount
** Parameters: Takes none.
************************************************/
BankAccount::~BankAccount()
{
	//automaticalling unallocated upon unscoping
}

/***********************************************
** Name: BankAccount::getCustomarName()
** Description: returns the getCustomarName object 
** Parameters: Takes none. Returns Name. 
************************************************/
string BankAccount::getCustomerName()
{
	return Name;
}

/***********************************************
** Name: BankAccount::getCustomarID()
** Description: returns the getCustomerID object 
** Parameters: Takes none. Returns ID.
************************************************/
string BankAccount::getCustomerID()
{
	return ID;
}

/***********************************************
** Name: BankAccount::getCustomarBalance()
** Description: returns Balance object 
** Parameters: Takes none. Returns Balance.
************************************************/
double BankAccount::getCustomerBalance()
{
	return Balance;
}

/***********************************************
** Name: BankAccount::setCustomarName()
** Description: sets object Name variable
** Parameters: Takes nam. Returns none.
************************************************/
void BankAccount::setCustomerName(double nam)
{
	Name = nam;
}

/***********************************************
** Name: BankAccount::setCustomarID()
** Description: sets object ID variable
** Parameters: takes ID. Returns none.
************************************************/
void BankAccount::setCustomerID(double ident)
{
	ID = ident;
}

/***********************************************
** Name: BankAccount::setCustomarBalance()
** Description: sets object Balance variable
** Parameters: takes Balance. Returns none.
************************************************/
void BankAccount::setCustomerBalance(double bal)
{
	Balance = bal;
}

/***********************************************
** Name: BankAccount::withdraw()
** Description: decreases balance by an amount
** Parameters: takes withd. returns none.
************************************************/
double BankAccount::withdraw(double withd)
{
	double newBalance = Balance -= withd;
	return newBalance;
}

/***********************************************
** Name: BankAccount::deposit()
** Description: increases balance by an amount
** Parameters: Takes depo. Returns none.
************************************************/
double BankAccount::deposit(double depo)
{
	double newBalance = Balance += depo;
	return newBalance;
}


/*
int main()
{

	BankAccount account1("Harry Potter", "K4637", 8032.78);
	//cout << account1.getCustomerName() << endl;
	//cout << account1.getCustomerID() << endl;
	//cout << account1.getCustomerBalance() << endl;
	account1.withdraw(244.00);
	//cout << account1.getCustomerBalance() << endl;
	account1.withdraw(3012.58);
	//cout << account1.getCustomerBalance() << endl;
	account1.deposit(37.54);
	//cout << account1.getCustomerBalance() << endl;
	account1.withdraw(1807.12);
	//cout << account1.getCustomerBalance() << endl;
	account1.deposit(500.00);
	//cout << account1.getCustomerBalance() << endl;
	double finalBalance = account1.getCustomerBalance();
	//cout << finalBalance << endl;
	return 0;
}
*/
int main()
{
    return 0;
}
