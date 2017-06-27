#include<iostream>
#include<process.h>
using namespace std;


class Vector {
private:
	double x, y, z;
public:
	Vector();
	Vector(double, double, double);
	Vector add(const Vector&);
	Vector sub(const Vector&);
	double dot(const Vector&);
	void read();
	void print();
	

};
int main() {

	Vector a(1.2, 2.4, 3.6), b, c, d;
	double m;
	b.read();
	c = a.add(b);
	d = a.sub(b);
	m = c.dot(d);
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
Vector::Vector(double a, double b,double c) {
	x = a;
	y = b;
	z = c;
}

Vector Vector::add(const Vector& a) {
	Vector c;
	c.x = x + a.x;
	c.y = y + a.y;
	c.z = z + a.z;
	return c;
}
Vector Vector::sub(const Vector& a) {
	Vector c;
	c.x = x - a.x;
	c.y = y - a.y;
	c.z = z - a.z;
	return c;
}
double Vector::dot(const Vector& a) {
	return (x*a.x+y*a.y+z*a.z);
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
