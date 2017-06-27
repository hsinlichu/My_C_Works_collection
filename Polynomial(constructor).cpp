#include<iostream>
#include<process.h>
#include<cmath>
using namespace std;

class poly {
private:
	int n;
	double *a;
public:
	poly();
	poly(double, double);
	poly(double, double, double);
	poly(double, double, double, double);
	~poly();
	double value(double);
};

poly::poly(): n(0)
{
	
	a = new double[1];
	*a = 0;
}
poly::poly(double a0, double a1) : n(2)
{
	a = new double[2];
	*a = a0;
	*(a + 1) = a1;
}
poly::poly(double a0, double a1, double a2 ) : n(3)
{
	a = new double[3];
	*a = a0;
	*(a + 1) = a1;
	*(a + 2) = a2;
}
poly::poly(double a0, double a1, double a2, double a3) : n(4)
{
	a = new double[4];
	*a = a0;
	*(a + 1) = a1;
	*(a + 2) = a2;
	*(a + 3) = a3;
}
poly::~poly()
{
	delete []a;
}
double poly::value(double x)
{
	double sum = 0;
	for (int i = 0; i < n; ++i)
	{
		//cout <<"coefficient"<< a[i] << endl;
		sum += a[i] * pow(x,i);
		//cout << "sum: " << sum << endl;
	}
	return sum;
}

int main() {

	poly f1(1, 2), f2(2, 3, -5), f3(-8, 2, -3, 5);
	cout << f1.value(1.2) << endl;
	cout << f2.value(1.2) << endl;
	cout << f3.value(1.2) << endl;



	system("pause");
	return 0;
}
