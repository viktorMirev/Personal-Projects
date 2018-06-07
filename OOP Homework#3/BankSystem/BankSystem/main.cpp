#include"Bank.h"
#include<iostream>
#include<string>
using namespace std;

const char * TITLE_PAGE = "1.  List customers\n2.  Add new customer\n3.  Delete customer\n4.  List all accounts\n5.  List customer accounts\n6.  Add new account\n7.  Delete account\n8.  Withdraw from account\n9.  Deposit to account\n10. Transfer\n11. Display info for the bank\n12. Quit";

void ClickToContinueFunk()
{
	cout << "Click any key to continue...";
	cin.ignore();
	cin.get();
	system("cls");
}

void DisplayTitle()
{
	cout << TITLE_PAGE << endl;
}


void Execute(int command,Bank & myBank)
{
	string custName;
	string custAddress;
	string iban;
	string ibanTr;
	int id;
	double amount;
	//clear console.
	system("cls");
	switch (command)
	{
		
	case 1:
		//LIST ALL CUSTOMERS
		myBank.listCustomers();
		ClickToContinueFunk();
		break;
	case 2:
		//ADD NEW CUSTOMER
		cout << "Enter customer ID: ";
		cin >> id;
		cout << "Enter customer Name: ";
		
		cin.ignore();
		getline(cin,custName);
		cout << "Enter customer Address: ";
		
		getline(cin, custAddress);

		myBank.addCustomer(id,custName.c_str(),custAddress.c_str());

		ClickToContinueFunk();

		break;
	case 3:
		//DELETE CUSTOMER
		cout << "Enter customer ID: ";
		cin >> id;
		myBank.deleteCustomer(id);

		ClickToContinueFunk();
		break;

	case 4:
		//LIST ALL ACCOUNTS
		myBank.listAccounts();

		ClickToContinueFunk();

		break;

	case 5:
		//LIST ALL CUST ACCOUNTS
		cout << "Enter customer ID: ";
		cin >> id;
		myBank.listCustomerAccount(id);

		ClickToContinueFunk();
		break;

	case 6 :
		//ADD NEW ACCOUNT
		cout << "Enter the type of the account( C for Current, S for Savings, P for Privilege) : ";
		char type;
		cin >> type;
		cout << "Enter the IBAN: ";
		cin.ignore();
		getline(cin, iban);
		cout << "Enter the Owner ID: ";
		cin >> id;
		cout << "enter the amount of money: ";
		cin >> amount;
		myBank.addAccount(type, iban.c_str(), id, amount);

		ClickToContinueFunk();
		break;
		
	case 7:
		//DELETE ACCOUNT
		cout << "Enter the IBAN of the account you want to DELETE: ";
		cin.ignore();
		getline(cin, iban);
		myBank.deleteAccount(iban.c_str());

		ClickToContinueFunk();
		break;

	case 8:
		//WITHDRAW FROM ACCOUNT
		cout << "Enter the amount of money you want to withdraw: ";
		cin >> amount;
		cin.ignore();
		cout << "Enter the IBAN of the account: ";
		getline(cin, iban);
		myBank.withdrawFromAccount(iban.c_str(), amount);

		ClickToContinueFunk();
		break;

	case 9:
		//DEPOSIT TO ACCOUNT
		cout << "Enter the amount of money you want to deposit: ";
		cin >> amount;
		cin.ignore();
		cout << "Enter the IBAN of the account: ";
		getline(cin, iban);
		myBank.depositToAccount(iban.c_str(), amount);

		ClickToContinueFunk();
		break;
	case 10:
		//TRANSFER
		cout << "Enter the amount of money you want to transfer: ";
		cin >> amount;
		cin.ignore();
		cout << "Enter the IBAN of the account you want to transfer FROM: ";
		getline(cin, iban);
		cout << "Enter the IBAN of the account you want to transfer TO: ";
		getline(cin, ibanTr);

		myBank.transfer(iban.c_str(), ibanTr.c_str(), amount);
		
		ClickToContinueFunk();
		break;

	case 11:
		//DISPLAY
		myBank.display();

		ClickToContinueFunk();
		break;

	default:
		return;
	}
}


int main()
{
	Bank myBank("ReichsBank", "Albert Speer Strasse Nummer 6m");
	while (true)
	{
		DisplayTitle();
		int command;
		cout << "Choose your option: ";
		cin >> command;
		if (command == 12)
		{
			ClickToContinueFunk();
			return 0;
		}
		
		Execute(command,myBank);
	}
}

