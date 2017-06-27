#include<iostream>
#include<process.h>
using namespace std;

class Student {
private:
	char name[20], number[20], department[20];
	int year;
public:
	void setName();
	void setNumber();
	void setDepartment();
	void setYear();
	void print();

};

int main() {

	Student A,B;
	cout << "Studern A:" << endl;
	A.setName();
	A.setNumber();
	A.setDepartment();
	A.setYear();
	A.print();


	cout << "Studern B:" << endl;
	B.setName();
	B.setNumber();
	B.setDepartment();
	B.setYear();
	B.print();



	system("pause");
	return 0;
}

void Student::setName() {
	cout << "Please enter your name:" << endl;
	cin >> name;
}
void Student::setNumber() {
	cout << "Please enter your number:" << endl;
	cin>>number;
}
void Student::setDepartment() {
	cout << "Please enter your department:" << endl;
	cin >> department;
}
void Student::setYear() {
	cout << "Please enter your year:" << endl;
	cin >> year;
}
void Student::print() {
	cout << "Your name: " << name << endl;
	cout << "Your number: " << number << endl;
	cout << "Your department: " << department << endl;
	cout << "Your year: " << year << endl;
}