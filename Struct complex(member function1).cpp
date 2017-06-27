#include<iostream>
#include<process.h>
using namespace std;

struct complex
{
	float real, imag;
	void add(const complex&, const complex&);
	void sub(const complex&, const complex&);
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
	C.add(A, B);
	C.output();

	cout << "For subtration:" << endl;
	C.sub(A, B);
	C.output();

	system("pause");
	return 0;
}

void complex::add(const complex& a, const complex& b)
{
	
	real = a.real + b.real;
	imag = a.imag + b.imag;
}
void complex::sub(const complex& a, const complex& b)
{
	real = a.real - b.real;
	imag = a.imag - b.imag;
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