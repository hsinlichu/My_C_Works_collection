#include<iostream>
#include<process.h>
using namespace std;

class vec2D
{
public:
	vec2D();
	vec2D(double, double);
	vec2D(const vec2D&);
	vec2D operator+(const vec2D&);
	vec2D operator-(const vec2D&);
	vec2D& operator=(const vec2D&);
	friend ostream& operator<<(ostream&, const vec2D&);
	friend istream& operator>>(istream&, vec2D&);

protected:
	double x, y;
};

vec2D::vec2D():x(0),y(0)
{
}
vec2D::vec2D(double a, double b):x(a),y(b)
{

}
vec2D::vec2D(const vec2D& a)
{
	(*this) = a;
}
vec2D vec2D::operator+(const vec2D& a)
{
	vec2D c;
	c.x = x + a.x;
	c.y = y + a.y;
	return c;
}
vec2D vec2D::operator-(const vec2D& a)
{
	vec2D c;
	c.x = x - a.x;
	c.y = y - a.y;
	return c;
}
vec2D& vec2D::operator=(const vec2D& a)
{
	x = a.x;
	y = a.y;
	return (*this);
}
ostream& operator<<(ostream& out, const vec2D& a)
{
	out << "(" << a.x << "," << a.y << ")" << endl;
	return out;
}
istream& operator>>(istream& in, vec2D& a)
{
	in >> a.x >> a.y;
	return in;
}

class vec3D :public vec2D
{
public:
	vec3D();
	vec3D(double, double, double);
	vec3D(const vec3D&);
	vec3D operator+(const vec3D&);
	vec3D operator-(const vec3D&);
	vec3D& operator=(const vec3D&);
	friend ostream& operator<<(ostream&, const vec3D&);
	friend istream& operator>>(istream&,  vec3D&);

protected:
	double z;

};

vec3D::vec3D() 
{
	x = 0;
	y = 0;
	z = 0;
}
vec3D::vec3D(double a, double b, double c) 
{
	x = a;
	y = b;
	z = c;
}
vec3D::vec3D(const vec3D& a)
{
	(*this) = a;
}
vec3D vec3D::operator+(const vec3D& a)
{
	vec3D c;
	c.x = x + a.x;
	c.y = y + a.y;
	c.z = z + a.z;
	return c;
}
vec3D vec3D::operator-(const vec3D& a)
{
	vec3D c;
	c.x = x - a.x;
	c.y = y - a.y;
	c.z = z - a.z;
	return c;
}
vec3D& vec3D::operator=(const vec3D& a)
{
	x = a.x;
	y = a.y;
	z = a.z;
	return (*this);
}
ostream& operator<<(ostream& out, const vec3D& a)
{
	out << "(" << a.x << "," << a.y << "," << a.z << ")" << endl;
	return out;
}
istream& operator>>(istream& in, vec3D& a)
{
	in >> a.x >> a.y >> a.z;
	return in;
}



int main() {
	vec2D a,b;
	vec3D c,d;
	cin >> a >> b;
	cin>> c >> d;
	cout << a - b << endl;
	cout << a + b << endl;
	cout << c-d << endl;
	cout << c+d << endl;



	system("pause");
	return 0;
}