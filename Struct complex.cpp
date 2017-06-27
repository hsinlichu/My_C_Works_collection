#include<iostream>
#include<process.h>
using namespace std;

struct complex
{
	float real,imag;
};

complex add(complex, complex);
complex sub(complex, complex);
void input(complex&);
void output(const complex&);

int main()
{
	complex A, B, C;
	cout << "Complex A:" << endl;
	input(A);
	cout << "Complex B:" << endl;
	input(B);
	cout << "For adding:" << endl;
	C = add(A, B);
	output(C);

	cout << "For subtration:" << endl;
	C = sub(A, B);
	output(C);

	system("pause");
	return 0;
}

complex add(complex a, complex b)
{
	complex c;
	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;
	return c;
}
complex sub(complex a, complex b)
{
	complex c;
	c.real = a.real - b.real;
	c.imag = a.imag - b.imag;
	return c;
}
void input(complex& a)
{
	
	cout << "Please input the real part of a complex :" << endl;
	cin >> a.real;
	
	cout << "Please input the imaginary  part of a complex :" << endl;
	cin >> a.imag;
}
void output(const complex& a)
{
	cout << "There is a complex :" << endl;
	cout << a.real;
	if(a.imag<0)cout<<a.imag << "i" << endl;
	else cout<< "+" << a.imag << "i" << endl;
}