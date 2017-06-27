#include<iostream>
#include<process.h>
using namespace std;

class Float {
private:
	float x;
public:
	Float() { x = 0.0; }
	Float(float a) { x = a; }
	Float add(Float);
	Float sub(Float);
	Float mul(Float);
	Float miv(Float);
	float getX();
};

int main() {
	Float a(1.2), b(2.4), c, d, e, f;
	c = a.add(b);
	d = a.sub(b);
	e = a.mul(b);
	f = a.miv(b);

	cout << "C: " << c.getX() << endl;
	cout << "D: " << d.getX() << endl;
	cout << "E: " << e.getX() << endl;
	cout << "F: " << f.getX() << endl;


	system("pause");
	return 0;
}

Float Float::add(Float a) {
	return x + a.getX();
}
Float Float::sub(Float a) {
	return x - a.getX();
}
Float Float::mul(Float a) {
	
	return x*a.getX();
}
Float Float::miv(Float a) {
	return x/a.getX();
}
float Float::getX() {
	return x;
}
