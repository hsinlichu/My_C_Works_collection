#include<iostream>
//#include<process.h>
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

class line {
private:
	int A, B, C;
public:
	line();
	line(int, int, int);
	line genator(coordinate, coordinate);
	int originTestUD();
	int originTestRL();
};
bool ycmp(coordinate, coordinate);
bool xcmp(coordinate, coordinate);
int main() {
	//while (true) {
		int a1, a2, b1, b2, c1, c2, d1, d2;
		cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2 >> d1 >> d2;
		coordinate inputA(a1, a2), inputB(b1, b2), inputC(c1, c2), inputD(d1, d2);
		coordinate input[] = { inputA ,inputB ,inputC ,inputD };
		sort(input, input + 4, ycmp);
		for (int i = 0;i < 4;i++)cout << "(" << input[i].readX() << "," << input[i].readY() << ")";
		cout << "\n-----------------------------\n";
		sort(input, input + 2, xcmp);
		sort(input+2, input+4, xcmp);
		for (int i = 0;i < 4;i++)cout <<"("<<input[i].readX()<<","<<input[i].readY() <<")";
		
		coordinate &ru= input[3], &rd= input[1], &ld= input[0], &lu= input[2];

		line a, b, c, d;
		line left, down, right, top;
		left = a.genator(lu, ld);
		down = a.genator(ld, rd);
		right = a.genator(rd, ru);
		top = a.genator(ru, lu);

		if (left.originTestRL() == 1 && down.originTestUD() == 1 && right.originTestRL() == 0 && top.originTestUD() == 0)cout << 1 << endl;
		else cout << 0 << endl;
		
	//}
	
	//system("pause");
	return 0;
}

bool ycmp(coordinate a, coordinate b) {
	return a.readY() < b.readY();
}
bool xcmp(coordinate a, coordinate b) {
	return a.readX() < b.readX();
}

coordinate::coordinate() {
	x = y = 0;
}
coordinate::coordinate(int a,int b) {
	x = a;
	y = b;
}
int coordinate::readX() {
	return x;	
}
int coordinate::readY() {
	return y;
}
line::line(int a, int b,int c) {
	A = a;
	B = b;
	C = c;
}
line::line() {
	A = B = C = 0;
}
line line::genator(coordinate a, coordinate b) {
	coordinate vector((b.readX() -a.readX()),(b.readY() -a.readY()));
	int coeA, coeB, coeC;

	coeB = -vector.readX();
	coeA = vector.readY();
	coeC = -(coeA*a.readX() + coeB*a.readY());

	line generated(coeA, coeB, coeC);
	return generated;
}
int line::originTestUD() {
	int testC;
	if (B < 0) {
		testC = -C;
	}
	else testC = C;
	if (testC > 0)return 1;
	else return 0;
}
int line::originTestRL() {
	int testC;
	if (A < 0) {
		testC = -C;
	}
	else testC = C;
	if (testC > 0)return 1;
	else return 0;
}

