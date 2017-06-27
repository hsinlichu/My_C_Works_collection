#include<iostream>
#include<process.h>
using namespace std;

class Vector
{
public:
	Vector();
	Vector(double, double, double);
	Vector(const Vector&);
	Vector operator+(const Vector&); //加減回傳值不能加& !! 
	Vector operator-(const Vector&);
	double operator*(const Vector&);
	Vector& operator=(const Vector&);
	void read();
	void print();

private:
	double x, y, z;
};

Vector::Vector()
{
	x = y = z = 0;
}
Vector::Vector(double a, double b, double c)
{
	x = a;
	y = b;
	z = c;
}
Vector::Vector(const Vector& a)
{
	(*this) = a;
}
Vector Vector::operator+(const Vector& a)
{
	Vector c;
	c.x = x + a.x;
	c.y = y + a.y;
	c.z = z + a.z;
	return c;
}
Vector Vector::operator-(const Vector& a)
{
	Vector c;
	c.x = x - a.x;
	c.y = y - a.y;
	c.z = z - a.z;
	return c;
}
double Vector::operator*(const Vector& a)
{
	return (x*a.x + y*a.y + z*a.z);
}
Vector& Vector::operator=(const Vector& a)
{
	x = a.x;
	y = a.y;
	z = a.z;
	return (*this);
}
void Vector::read()
{
	cout << "Please input a vector:" << endl;
	cin >> x >> y >> z;
}
void Vector::print()
{
	cout << "(" << x << "," << y << "," << z << ")" << endl;
}


int main()
{
	Vector a, b(3.4, 2.6, 1.3), c, d;
	a.read();
	Vector e(a);
	c = a + b;
	d = a - b;
	int m;
	m = d*e;
	cout << "a: ";
	a.print();
	cout << "b: ";
	b.print(); 
	cout << "c: ";
	c.print();
	cout << "d: ";
	d.print();
	cout << "e: ";
	e.print();
	cout << "m: " << m << endl;



	system("pause");
	return 0;
}
