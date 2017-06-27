#include<iostream>
#include<process.h>
#include<array>
#include<string>
using namespace std;

class person
{
public:
	person() ;
	person(char*, char*, char*, int);
	~person();
	int getage() { return age; }
	char *getid() { return id; }
	char *getname() { return name; }
	char *getaddress() { return address; }
	void print();
protected:
	char *name, *id, *address;
	int age;
};

person::person():age(0)
{
	name = id = address = NULL;
}
person::person(char* a, char* b, char* c, int d) : age(d)
{
	name = new char[strlen(a)+1];
	strcpy(name, a);
	id = new char[strlen(b) + 1];
	strcpy(id, b);
	address = new char[strlen(c) + 1];
	strcpy(address, c);
}
person::~person()
{
	delete id;
	delete name;
	delete address;
}
void person::print()
{
	cout << "name:" << name << endl;
	cout << "id:" << id << endl;
	cout << "address:" << address << endl;
}
class Account
{
public:
	Account();
	Account( int, int, long);
	long deposit();
	long withdraw();
	int changepassword();
	long query();

protected:
	int accid;
	int password;
	long balance;
	bool state = 1;
	bool checkpassword();
	int wrongTimes = 0;

};

Account::Account()
{
	//char initial[] = "admin";
	//strcpy_s(name,initial);
	password = 0;
	balance = 0;
	accid = 0;

}
Account::Account(int b, int c, long d)
{
	accid = b;
	password = c;
	balance = d;
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
	bool check = checkpassword();
	if (check == 0)return 0;
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
	bool check = checkpassword();
	if (check == 0)return 0;
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
	bool check = checkpassword();
	if (check == 0)return 0;
	else
	{
		cout << "Your balance: " << balance << endl;
		return balance;
	}
}
int Account::changepassword()
{
	bool check = checkpassword();
	if (check == 0)return 0;
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

class personaccount:public person, public Account
{
public:
	personaccount();
	personaccount(char*, char*, char*, int, int, int, long);
	void open();
};
personaccount::personaccount()
{
	person("admin", "A123456789", "N0.1,Sec.4,R00sevelt,Road,Taipei", 30);
	Account(5436127, 1234, 0);
}
personaccount::personaccount(char* a, char* b, char* c, int d, int e, int f, long g)
{
	person(a,b,c,d);
	Account(e, f, g);
}
void personaccount::open() 
{
	char *a, *b, *c;
	
	cout << "Please enter your name:";
	delete name;
	a = new char[80];
	cin >> a;
	name = new char[strlen(a) + 1];
	strcpy(name, a);
	cout << "Please enter your id:";
	delete id;
	b = new char[80];
	cin >> b;
	id = new char[strlen(b) + 1];
	strcpy(name, b);
	delete address;
	cout << "Please enter your address:";
	c = new char[80];
	cin >> c;
	address = new char[strlen(c) + 1];
	strcpy(name, c);
	cout << "Please enter your accid:";
	cin >> accid;
	cout << "Please enter your password:";
	cin >> password;
	cout << "Please enter your balance:";
	cin >> balance;
	cout << "You have successfully open an account." << endl;
}


int main() {
	personaccount admin, user;
	user.open();
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