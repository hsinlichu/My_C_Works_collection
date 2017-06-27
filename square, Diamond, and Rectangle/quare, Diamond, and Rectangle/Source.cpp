#include<iostream>
//#include<process.h>
#include<cmath>
#include<algorithm>
using namespace std;

class coordinate {
private:
	int x, y;
public:
	coordinate();
	coordinate(int, int);
	coordinate(const coordinate&);
	int operator*(coordinate);
	coordinate operator-(coordinate);
	int readX();
	int readY();
};
class polygon {
private:
	coordinate A, B, C, D;
	double abSquare, bcSquare, cdSquare, daSquare;
public:
	polygon(coordinate const[]);
	void typeCheck();

};

bool ycmp(coordinate, coordinate);
bool xcmpd(coordinate, coordinate);
bool xcmpu(coordinate, coordinate);

int main() {
	int times;
	cin >> times;
	for (int i = 0;i < times;i++) {
		int a1, a2, b1, b2, c1, c2, d1, d2;
		cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2 >> d1 >> d2;
		coordinate inputA(a1, a2), inputB(b1, b2), inputC(c1, c2), inputD(d1, d2);
		coordinate input[] = { inputA,inputB,inputC,inputD };
		sort(input, input + 4, ycmp);
		sort(input, input + 2, xcmpd);
		sort(input + 2, input + 4, xcmpu);
		polygon test(input);
		test.typeCheck();		
	}


	//system("pause");
	return 0;
}

coordinate::coordinate() {
	x = y = 0;
}
coordinate::coordinate(int a, int b) {
	x = a;
	y = b;
}
coordinate::coordinate(const coordinate &a) {
	x = a.x;
	y = a.y;
}
int coordinate::readX() {
	return x;
}
int coordinate::readY() {
	return y;
}

int coordinate::operator*(coordinate a)
{
	return (this->x*a.x + this->y*a.y);
}
coordinate coordinate::operator-(coordinate a)
{
	coordinate c;
	c.x = x - a.x;
	c.y = y - a.y;
	return c;
}

bool ycmp(coordinate a, coordinate b) {
	return a.readY() < b.readY();
}
bool xcmpd(coordinate a, coordinate b) {
	return a.readX() < b.readX();
}
bool xcmpu(coordinate a, coordinate b) {
	return a.readX() > b.readX();
}

polygon::polygon(coordinate const a[]) {
	A = a[0];
	B = a[1];
	C = a[2];
	D = a[3];
	abSquare = pow((B.readX() - A.readX()), 2) + pow((B.readY() - A.readY()), 2);
	bcSquare = pow((C.readX() - B.readX()), 2) + pow((C.readY() - B.readY()), 2);
	cdSquare = pow((D.readX() - C.readX()), 2) + pow((D.readY() - C.readY()), 2);
	daSquare = pow((A.readX() - D.readX()), 2) + pow((A.readY() - D.readY()), 2);
}

void polygon::typeCheck() {
	int lenthSquare[] = { abSquare, bcSquare, cdSquare,daSquare };
	coordinate ab(B - A), bc(C - B), cd(D - C), da(A - D);

	if ((lenthSquare[0] == lenthSquare[1]) && (lenthSquare[1] == lenthSquare[2]) && (lenthSquare[2] == lenthSquare[3]))
	{
		if ((ab * bc) == 0 && (bc*cd) == 0 && (cd*da) == 0 && (da*ab) == 0)
		{
			cout << "square" << endl;
		}
		else cout << "diamond" << endl;
	}
	else if ((ab * bc) == 0 && (bc*cd) == 0 && (cd*da) == 0 && (da*ab) == 0)
	{
		cout << "rectangle" << endl;
	}
	else cout << "other" << endl;

}

