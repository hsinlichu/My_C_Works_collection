#include<iostream>
#include<process.h>
#include<array>
#include<string>
using namespace std;

class Account
{
public:
	Account();
	Account(char[], int, int, long);
	long deposit();
	long withdraw();
	int changepassword();
	long query();

private:
	char name[20];
	int password;
	long balance;
	bool state = 1;
	int id;
	bool checkpassword();
	int wrongTimes = 0;

};

Account::Account()
{
	char initial[] = "admin";
	strcpy_s(name, initial);
	password = 1234;
	balance = 0;
	id = 00000;

}
Account::Account(char a[], int b, int c, long d)
{
	strcpy(name, a);
	password = b;
	balance = c;
	id = d;
}
bool Account::checkpassword() {
	if (wrongTimes == 3)
	{
		cout << "You have enter wrong password 3 times,please ask our customer service." << endl;
		return 0;
	}
	cout << "Please enter your password: ";
	int enter;
	cin >> enter;
	cout << "\n";

	if (enter != password)
	{
		cout << "You enter a wrong password!" << endl;
		wrongTimes++;
		//cout << wrongTimes << endl;
		if (wrongTimes == 3)
		{
			cout << "You have enter wrong password 3 times,please ask our customer service." << endl;
			return 0;
		}
		else
		{
			cout << "You remain " << 3 - wrongTimes << " times chance to enter password.";
		}
		return 0;
	}
	else
	{
		wrongTimes = 0;
		return 1;
	}
}
long Account::deposit()
{
	state = checkpassword();
	if (state == 0)return 0;
	else
	{
		int money;
		cout << "Please enter how much you want deposit: ";
		cin >> money;
		balance += money;
	}
	return balance;
}
long Account::withdraw()
{
	state = checkpassword();
	if (state == 0)return 0;
	else
	{
		int money;
		cout << "Please enter how much you want withdraw: ";
		cin >> money;
		if (money > balance)cout << "You don't have enough money." << endl;
		else balance -= money;
	}
	return balance;
}
long Account::query()
{
	state = checkpassword();
	if (state == 0)return 0;
	else
	{
		cout << "Your balance: " << balance << endl;
		return balance;
	}
}
int Account::changepassword()
{
	state = checkpassword();
	if (state == 0)return 0;
	else
	{
		int input;
		cout << "Please your new password: ";
		cin >> input;
		cout << "\n";
		password = input;
		return password;
	}
}



int main() {
	Account admin, user("james", 5678, 0, 123456);
	while (true)
	{
		int action;
		cout << "What you want to do? " << endl;
		cout << "Enter 1.deposit 2.withdraw 3.query 4.changepassword" << endl;
		cin >> action;
		switch (action)
		{
		case 1:
			user.deposit();
			break;
		case 2:
			user.withdraw();
			break;
		case 3:
			user.query();
			break;
		case 4:
			user.changepassword();
			break;
		default:
			cout << "Your action input is wrong." << endl;
			break;
		}
	}


	system("pause");
	return 0;
}
