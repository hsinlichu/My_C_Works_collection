#include<iostream>
#include<process.h>
using namespace std;


class Vector {
private:
	double x, y, z;
public:
	Vector();
	Vector(double, double, double);
	void read();
	void print();
	Vector operator +(const Vector&);
	Vector operator -(const Vector&);
	double operator *(const Vector&);


};
int main() {

	Vector a(1.2, 2.4, 3.6), b, c, d;
	double m;
	b.read();
	c = a+b;
	d = a-b;
	m = c*d;
	cout << "ADD:" << endl;
	c.print();
	cout << "SUB:" << endl;
	d.print();
	cout << "DOT:" << endl;
	cout << m << endl;



	system("pause");
	return 0;
}

Vector::Vector() {
	x = y = z = 0;
}
Vector::Vector(double a, double b, double c) {
	x = a;
	y = b;
	z = c;
}

void Vector::read() {
	cout << "Please enter x direction:" << endl;
	cin >> x;
	cout << "Please enter y direction:" << endl;
	cin >> y;
	cout << "Please enter z direction:" << endl;
	cin >> z;
}
void Vector::print() {
	cout << "(" << x << "," << y << "," << z << ")" << endl;
}

Vector Vector::operator +(const Vector& a) {
	Vector c;
	c.x = x + a.x;
	c.y = y + a.y;
	c.z = z + a.z;
	return c;
}
Vector Vector::operator -(const Vector& a) {
	Vector c;
	c.x = x - a.x;
	c.y = y - a.y;
	c.z = z - a.z;
	return c;
}
double Vector::operator *(const Vector& a) {
	return (x * a.x+ y * a.y+ z * a.z);
}