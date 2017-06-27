#include<iostream>
#include<process.h>
using namespace std;

struct complex
{
	float real, imag;
	complex add(const complex&);
	complex sub(const complex&);
	void input();
	void output();
};



int main()
{
	complex A, B, C;
	cout << "Complex A:" << endl;
	A.input();
	cout << "Complex B:" << endl;
	B.input();
	cout << "For adding:" << endl;
	C=A.add(B);
	C.output();

	cout << "For subtration:" << endl;
	C=A.sub(B);
	C.output();

	system("pause");
	return 0;
}

complex complex::add(const complex& b)
{
	complex c;
	c.real = real + b.real;
	c.imag = imag + b.imag;
	return c;
}
complex complex::sub(const complex& b)
{	
	complex c;
	c.real = real - b.real;
	c.imag = imag - b.imag;
	return c;
}
void complex::input()
{
	cout << "Please input the real part of a complex :" << endl;
	cin >> real;
	cout << "Please input the imaginary  part of a complex :" << endl;
	cin >> imag;
}
void complex::output()
{
	cout << "There is a complex :" << endl;
	cout << real;
	if (imag<0)cout << imag << "i" << endl;
	else cout << "+" << imag << "i" << endl;
}