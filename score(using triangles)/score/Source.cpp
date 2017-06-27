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
	int readX();
	int readY();
};
class triangles {
private:
	coordinate A, B, C;
	double abSquare, bcSquare, acSquare;
public:
	triangles(coordinate, coordinate, coordinate);
	void typeCheck();

};

int main() {
	int times;
	cin >> times;
	for (int i = 0;i < times;i++) {
		int a1, a2, b1, b2, c1, c2;
		cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
		coordinate inputA(a1, a2), inputB(b1, b2), inputC(c1, c2);
		triangles input(inputA, inputB, inputC);
		input.typeCheck();
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
int coordinate::readX() {
	return x;
}
int coordinate::readY() {
	return y;
}
triangles::triangles(coordinate a, coordinate b, coordinate c) {
	A = a;
	B = b;
	C = c;
	abSquare = pow((b.readX() - a.readX()), 2) + pow((b.readY() - a.readY()), 2);
	bcSquare = pow((c.readX() - b.readX()), 2) + pow((c.readY() - b.readY()), 2);
	acSquare = pow((c.readX() - a.readX()), 2) + pow((c.readY() - a.readY()), 2);
}
void triangles::typeCheck() {
	int lenthSquare[] = { abSquare, bcSquare, acSquare };
	sort(lenthSquare, lenthSquare + 3);
	//for (int i = 0;i < 3;i++)cout <<"lenthSquare"<< lenthSquare[i] << ",";
	//cout << endl;
	if ((lenthSquare[0] == lenthSquare[1])|| (lenthSquare[1] == lenthSquare[2]))cout << "isosceles" << endl;
	else if((lenthSquare[0] + lenthSquare[1])== lenthSquare[2])cout << "right" << endl;
	else if ((lenthSquare[0] + lenthSquare[1]) < lenthSquare[2])cout << "obtuse" << endl;
	else if ((lenthSquare[0] + lenthSquare[1]) > lenthSquare[2])cout << "acute" << endl;
	
}