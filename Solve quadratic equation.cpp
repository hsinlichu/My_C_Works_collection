#include<iostream>
#include<process.h>
using namespace std;

class Leqs {
private:
	double a, b, c, d, e, f;
	double x, y;
	int flag;
public:
	void read();
	void solve();
	void print();
};
int main() {

	while (1) {
		Leqs a;
		a.read();
		a.solve();
		a.print();
	}

	system("pause");
	return 0;
}
void Leqs::read() {
	cout << "Please enter the coefficint:" << endl;
	cin >> a >> b >> c >> d >> e >> f;
}
void Leqs::solve() {
	
	if ((a*e - b*d) == 0 && (a*f - c*d) == 0)flag = -1;
	else if ((a*e - b*d) == 0 && (a*f - c*d) != 0)flag = 0;
	else if ((a*e - b*d) != 0) {
		flag = 1;
		x = (c*e - b*f) / (a*e - b*d);
		y = (a*f - c*d) / (a*e - b*d);
	}
}

void Leqs::print() {
	switch (flag) {
	case -1:
		cout << "Infinite solution" << endl;
		break;
	case 0:
		cout << "No solution" << endl;
		break;
	case 1:
		cout << "There is one solution:\n" << "x=" << x << "\ny=" << y << endl;
		break;
	default:
		cout << "You should never reach here!!" << endl;
	}
}